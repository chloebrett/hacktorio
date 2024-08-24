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
#include "item_stack.hpp"
#include <vector>
#include "cursor_state.hpp"

Renderer::Renderer(sf::RenderWindow &window,
                   Player &player,
                   Environment &environment,
                   Chest &chest,
                   SceneNode &rootSceneNode,
                   CursorState &cursorState)
    : window(window),
      player(player),
      environment(environment),
      chest(chest), rootSceneNode(rootSceneNode), cursorState(cursorState) {
        sf::Vector2f SCREEN_SIZE = sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT);
        sf::Color blue = sf::Color(81.0f, 168.0f, 194.0f, 255.0f);
};

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

    // Left inventory
    player.updateItems();
    vector<ItemStack>& items = player.getItems();
    int size = player.getItems().size();
    for (int y = 0; y < INVENTORY_HEIGHT_CELLS; y++)
    {
        for (int x = 0; x < INVENTORY_WIDTH_CELLS; x++)
        {
            sf::RectangleShape itemRect;
            itemRect.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE));
            itemRect.setPosition(INVENTORY_H_MARGIN + INVENTORY_PADDING + x * GRID_SIZE, INVENTORY_V_MARGIN + INVENTORY_PADDING + y * GRID_SIZE);
            itemRect.setFillColor(sf::Color(0, 0, 0, 0));
            itemRect.setOutlineColor(sf::Color(40, 40, 40, 255));
            itemRect.setOutlineThickness(1.0);
            window.draw(itemRect);

            int index = y * INVENTORY_WIDTH_CELLS + x;
            if (index < items.size()) {
                InventoryItemType inventoryItemType = items[index].getType();
                int count = items[index].getAmount();

                sf::Texture texture;
                if (!texture.loadFromFile(inventoryItemTypeToFilename(inventoryItemType)))
                {
                    // Handle loading error
                    cout << "Failed to load texture" << endl;
                }
                sf::Sprite sprite(texture);
                sprite.setTextureRect(sf::IntRect(64, 0, 32, 32));
                sprite.setPosition(INVENTORY_H_MARGIN + INVENTORY_PADDING + x * GRID_SIZE, INVENTORY_V_MARGIN + INVENTORY_PADDING + y * GRID_SIZE);

                window.draw(sprite);

                sf::Text text;
                text.setFont(font);
                text.setString(to_string(count));
                text.setCharacterSize(12);
                text.setFillColor(sf::Color::White);
                text.setPosition(INVENTORY_H_MARGIN + INVENTORY_PADDING + x * GRID_SIZE + 16, INVENTORY_V_MARGIN + INVENTORY_PADDING + y * GRID_SIZE + 16);
                window.draw(text);
            }
        }
    }

    // Right inventory
    for (int i = 0; i < INVENTORY_WIDTH_CELLS; i++)
    {
        for (int j = 0; j < INVENTORY_HEIGHT_CELLS; j++)
        {
            sf::RectangleShape itemRect;
            itemRect.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE));
            itemRect.setPosition(INVENTORY_H_MARGIN + INVENTORY_WIDTH + INVENTORY_PADDING * 2 + i * GRID_SIZE, INVENTORY_V_MARGIN + INVENTORY_PADDING + j * GRID_SIZE);
            itemRect.setFillColor(sf::Color(0, 0, 0, 0));
            itemRect.setOutlineColor(sf::Color(40, 40, 40, 255));
            itemRect.setOutlineThickness(1.0);
            window.draw(itemRect);
        }
    }

    sf::Text text;
    text.setFont(font);
    text.setString("Hello, World!");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(10, 70);
    window.draw(text);
}

void Renderer::render(bool isInventoryOpen, int selectedInventoryItemIndex, int selectedOtherItemIndex, sf::Vector2i mousePosition)
{
    window.clear();

    rootSceneNode.render(window, sf::Vector2f(0, 0));

    // renderScene();
    // renderGui(isInventoryOpen, selectedInventoryItemIndex, selectedOtherItemIndex, mousePosition);
    window.display();
}

void Renderer::renderGui(bool isInventoryOpen, int selectedInventoryItemIndex, int selectedOtherItemIndex, sf::Vector2i mousePosition)
{
    if (isInventoryOpen)
    {
        drawInventory(window, player, selectedInventoryItemIndex);
    }
}
