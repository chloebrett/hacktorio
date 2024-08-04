#include "renderer.hpp"
#include "constants.hpp"
#include "SFML/Graphics.hpp"
#include "player.hpp"
#include "resource_patch.hpp"
#include "game.hpp"
#include "resource_patch.hpp"
#include "inventory_item_type.hpp"
#include "resource_patch_type.hpp"
#include <iostream>
#include <memory>
#include "chest.hpp"
#include <vector>

std::map<ResourcePatchType, sf::Color> getResourcePatchColors()
{
    std::map<ResourcePatchType, sf::Color> resourcePatchColors;
    resourcePatchColors[ResourcePatchType::IRON] = sf::Color(80, 81, 84, 255);
    resourcePatchColors[ResourcePatchType::COAL] = sf::Color(23, 21, 16, 255);
    resourcePatchColors[ResourcePatchType::COPPER] = sf::Color(150, 104, 68, 255);
    resourcePatchColors[ResourcePatchType::STONE] = sf::Color(145, 145, 108, 255);
    resourcePatchColors[ResourcePatchType::WOOD] = sf::Color(84, 64, 48, 255);
    return resourcePatchColors;
}

void drawChest(sf::RenderWindow &window, Chest &chest)
{
    sf::Texture texture;
    if (!texture.loadFromFile("data/base/graphics/entity/wooden-chest/wooden-chest.png"))
    {
        // Handle loading error
        cout << "Failed to load texture" << endl;
    }
    sf::Sprite sprite(texture);
    sprite.setPosition(chest.getPosition());
    window.draw(sprite);
}

std::string inventoryItemTypeToString(InventoryItemType inventoryItemType)
{
    switch (static_cast<int>(inventoryItemType))
    {
    case static_cast<int>(InventoryItemType::IRON_ORE):
        return "Iron Ore";
    case static_cast<int>(InventoryItemType::COAL):
        return "Coal";
    case static_cast<int>(InventoryItemType::COPPER_ORE):
        return "Copper Ore";
    case static_cast<int>(InventoryItemType::STONE):
        return "Stone";
    case static_cast<int>(InventoryItemType::WOOD):
        return "Wood";
    case static_cast<int>(InventoryItemType::IRON_PLATE):
        return "Iron Plate";
    case static_cast<int>(InventoryItemType::STEEL):
        return "Steel";
    case static_cast<int>(InventoryItemType::COPPER_PLATE):
        return "Copper Plate";
    case static_cast<int>(InventoryItemType::STONE_BRICK):
        return "Stone Bricket";
    case static_cast<int>(InventoryItemType::STONE_FURNACE):
        return "Stone Furnace";
    default:
        return "Unknown";
    }
}

std::string inventoryItemTypeToFilename(InventoryItemType inventoryItemType)
{
    switch (static_cast<int>(inventoryItemType))
    {
    case static_cast<int>(InventoryItemType::IRON_ORE):
        return "data/base/graphics/icons/iron-ore.png";
    case static_cast<int>(InventoryItemType::COAL):
        return "data/base/graphics/icons/coal.png";
    case static_cast<int>(InventoryItemType::COPPER_ORE):
        return "data/base/graphics/icons/copper-ore.png";
    case static_cast<int>(InventoryItemType::STONE):
        return "data/base/graphics/icons/stone.png";
    case static_cast<int>(InventoryItemType::WOOD):
        return "data/base/graphics/icons/wood.png";
    case static_cast<int>(InventoryItemType::IRON_PLATE):
        return "data/base/graphics/icons/iron-plate.png";
    case static_cast<int>(InventoryItemType::STEEL):
        return "data/base/graphics/icons/steel.png";
    case static_cast<int>(InventoryItemType::COPPER_PLATE):
        return "data/base/graphics/icons/copper-plate.png";
    case static_cast<int>(InventoryItemType::STONE_BRICK):
        return "data/base/graphics/icons/stone-brick.png";
    case static_cast<int>(InventoryItemType::STONE_FURNACE):
        return "data/base/graphics/icons/stone-furnace.png";
    default:
        return "data/core/graphics/cancel.png";
    }
}

void drawInventory(sf::RenderWindow &window, Player &player, int selectedIndex)
{
    sf::Font font;
    if (!font.loadFromFile("res/Inconsolata-Regular.ttf"))
    {
        std::cout << "Failed to load font" << std::endl;
    }

    int i = 0;
    for (const auto &item : player.getContents())
    {
        InventoryItemType inventoryItemType = item.first;
        int count = item.second;

        sf::Texture texture;
        if (!texture.loadFromFile(inventoryItemTypeToFilename(inventoryItemType)))
        {
            // Handle loading error
            cout << "Failed to load texture" << endl;
        }
        sf::Sprite sprite(texture);
        sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
        sprite.setPosition(10, 10 + 64 * (i + 1));

        window.draw(sprite);
        i++;
    }
}

void drawChestContentsIfNear(sf::RenderWindow &window, Chest &chest, Player &player, int selectedIndex)
{
    sf::Font font;
    if (!font.loadFromFile("res/Inconsolata-Regular.ttf"))
    {
        std::cout << "Failed to load font" << std::endl;
    }

    sf::Vector2f playerPosition = player.getPosition();
    sf::Vector2f chestPosition = chest.getPosition();
    sf::Vector2f diff = playerPosition - chestPosition;
    if (abs(diff.x) < 2 * GRID_SIZE && abs(diff.y) < 2 * GRID_SIZE)
    {
        std::map<InventoryItemType, int> chestContents = chest.getContents();

        int i = 0;
        for (const auto &item : chestContents) // TODO: Be careful about ordering - is this deterministic?
        {
            InventoryItemType inventoryItemType = item.first;
            int count = item.second;

            sf::Texture texture;
            if (!texture.loadFromFile(inventoryItemTypeToFilename(inventoryItemType)))
            {
                // Handle loading error
                cout << "Failed to load texture" << endl;
            }
            sf::Sprite sprite(texture);
            sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
            sprite.setPosition(200, 10 + 64 * (i + 1));

            window.draw(sprite);
            i++;
        }
    }
}

Renderer::Renderer(sf::RenderWindow &window,
                   Player &player,
                   Environment &environment,
                   Chest &chest)
    : window(window),
      player(player),
      environment(environment),
      chest(chest) {
        sf::Vector2f SCREEN_SIZE = sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT);
        sf::Color green = sf::Color(85.0f, 107.0f, 95.0f, 255.0f);
        sf::Color blue = sf::Color(81.0f, 168.0f, 194.0f, 255.0f);

        sf::RectangleShape background;
        background.setSize(SCREEN_SIZE);
        background.setPosition(0.0f, 0.0f);
        background.setFillColor(green);
        this->background = background;

        sf::RectangleShape playerRect;
        playerRect.setSize(sf::Vector2f(1 * GRID_SIZE, 1 * GRID_SIZE));
        playerRect.setPosition(2 * GRID_SIZE, 2 * GRID_SIZE);
        playerRect.setFillColor(blue);
        this->playerRect = playerRect;
};

void Renderer::render(bool isInventoryOpen, int selectedInventoryItemIndex, int selectedOtherItemIndex, sf::Vector2i mousePosition)
{
    window.clear();
    renderBackground();
    renderScene();
    renderGui(isInventoryOpen, selectedInventoryItemIndex, selectedOtherItemIndex, mousePosition);
    window.display();
}

void Renderer::renderBackground()
{
    window.draw(background);
}

void Renderer::renderScene()
{
    std::map<ResourcePatchType, sf::Color> resourcePatchColors = getResourcePatchColors();
    for (ResourcePatch& resourcePatch : environment.getResourcePatches())
    {
        if (resourcePatch.getRemaining() > 0)
        {
            sf::RectangleShape resourcePatchRect;
            resourcePatchRect.setSize(sf::Vector2f(1 * GRID_SIZE, 1 * GRID_SIZE));
            sf::Vector2f resourcePatchPosition = resourcePatch.getPosition();
            resourcePatchRect.setPosition(resourcePatchPosition);
            resourcePatchRect.setFillColor(resourcePatchColors[resourcePatch.getType()]);
            window.draw(resourcePatchRect);
        }
    }
    playerRect.setPosition(player.getPosition());
    window.draw(playerRect);
}

void drawCursor(sf::RenderWindow &window, sf::Vector2i mousePosition)
{
    sf::RectangleShape cursorRect;
    cursorRect.setSize(sf::Vector2f(1 * GRID_SIZE, 1 * GRID_SIZE));
    cursorRect.setPosition(mousePosition.x, mousePosition.y);
    cursorRect.setFillColor(sf::Color(255, 255, 255, 255));
    window.draw(cursorRect);
}

void Renderer::renderGui(bool isInventoryOpen, int selectedInventoryItemIndex, int selectedOtherItemIndex, sf::Vector2i mousePosition)
{
    if (isInventoryOpen)
    {
        drawInventory(window, player, selectedInventoryItemIndex);
    }
    drawChest(window, chest);
    drawChestContentsIfNear(window, chest, player, selectedOtherItemIndex);
    drawCursor(window, mousePosition);
}
