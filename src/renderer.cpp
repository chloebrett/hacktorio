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
    sf::RectangleShape chestRect;
    chestRect.setSize(sf::Vector2f(1 * GRID_SIZE, 1 * GRID_SIZE));
    chestRect.setPosition(chest.getPosition());
    chestRect.setFillColor(sf::Color(0, 0, 0, 255));
    window.draw(chestRect);
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

        sf::Text inventoryText(inventoryItemTypeToString(inventoryItemType) + ": " + std::to_string(count), font);
        inventoryText.setCharacterSize(24);
        inventoryText.setFillColor(sf::Color::White);
        inventoryText.setPosition(10, 10 + 30 * (i + 1));

        if (i == (selectedIndex % player.getContents().size()))
        {
            inventoryText.setFillColor(sf::Color::Red);
        }

        window.draw(inventoryText);
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

            sf::Text inventoryText(inventoryItemTypeToString(inventoryItemType) + ": " + std::to_string(count), font);
            inventoryText.setCharacterSize(24);
            inventoryText.setFillColor(sf::Color::White);
            inventoryText.setPosition(200, 10 + 30 * (i + 1));

            if (i == (selectedIndex % chestContents.size()))
            {
                inventoryText.setFillColor(sf::Color::Red);
            }

            window.draw(inventoryText);
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
