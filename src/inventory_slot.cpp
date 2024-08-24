#pragma once

#include <iostream>
#include "container.hpp"
#include "inventory.hpp"
#include "scene_node.hpp"
#include "SFML/Graphics.hpp"
#include <functional>
#include <vector>
#include "constants.hpp"
#include "renderer.hpp"
#include "constants.hpp"
#include "SFML/Graphics.hpp"
#include "player.hpp"
#include "resource_patch.hpp"
#include "inventory_left.hpp"
#include "game.hpp"
#include "game_resources.hpp"
#include "resource_patch.hpp"
#include "inventory_item_type.hpp"
#include "resource_patch_type.hpp"
#include <iostream>
#include <memory>
#include "chest.hpp"
#include "item_stack.hpp"
#include <vector>
#include "cursor_state.hpp"
#include "inventory_slot.hpp"

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
        return "Stone Brick";
    case static_cast<int>(InventoryItemType::STONE_FURNACE):
        return "Stone Furnace";
    default:
        return "Unknown";
    }
}

InventorySlot::InventorySlot(int row, int column, int index, Container &container) : row(row), column(column), index(index), container(container), SceneNode(
    /* position= */ sf::Vector2f(column * GRID_SIZE, row * GRID_SIZE),
    /* size= */ sf::Vector2f(GRID_SIZE, GRID_SIZE),
    /* onClick= */ [row, column]() {
        std::cout << "Inventory slot (" << column << "," << row << ") clicked" << std::endl;
    },
    /* onRender= */ [this, index, &container](
        SceneNode &node,
        sf::RenderWindow &window,
        sf::Vector2f absolutePos
    ) {
        sf::RectangleShape itemRect;
        itemRect.setPosition(absolutePos);
        itemRect.setSize(size);
        itemRect.setFillColor(sf::Color(0, 0, 0, 0));
        itemRect.setOutlineColor(sf::Color(40, 40, 40, 255));
        itemRect.setOutlineThickness(1.0);
        window.draw(itemRect);

        vector<ItemStack>& items = container.getItems();
        if (index >= items.size())
        {
            return;
        }
        ItemStack* itemStack = &items[index];
        int count = itemStack->getAmount();

        sf::Sprite sprite = *GameResources::getInstance().getInventorySprite(itemStack->getType());
        sprite.setPosition(absolutePos);
        window.draw(sprite);

        sf::Font font = *GameResources::getInstance().getFont("main");
        sf::Text text;
        text.setFont(font);
        text.setString(to_string(count));
        text.setCharacterSize(12);
        text.setFillColor(sf::Color::White);
        text.setPosition(absolutePos.x + 16, absolutePos.y + 16); // TODO: separate class?
        window.draw(text);
    }
) {}
