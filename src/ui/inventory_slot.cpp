#include "inventory_slot.hpp"

#include <functional>
#include <iostream>
#include <memory>
#include <vector>

#include "../config/constants.hpp"
#include "../config/game_resources.hpp"
#include "../config/inventory_item_type.hpp"
#include "../config/resource_patch_type.hpp"
#include "../container.hpp"
#include "../item_stack.hpp"
#include "../player.hpp"
#include "../renderer.hpp"
#include "../resource_patch.hpp"
#include "../scene_node.hpp"
#include "SFML/Graphics.hpp"
#include "inventory_grid.hpp"
#include "panel.hpp"

std::string inventoryItemTypeToString(InventoryItemType inventoryItemType) {
    switch (static_cast<int>(inventoryItemType)) {
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
        // case static_cast<int>(InventoryItemType::STEEL):
        //     return "Steel";
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

InventorySlot::InventorySlot(int row, int column, int index, InventoryGrid& grid)
    : row(row),
      column(column),
      index(index),
      grid(grid),
      SceneNode(
          /* position= */
          sf::Vector2f(column * GRID_SIZE, row * GRID_SIZE),
          /* size= */ sf::Vector2f(GRID_SIZE, GRID_SIZE),
          /* onClick= */
          [row, column, index, &grid](Cursor& cursor) {
              std::cout << "Inventory slot (" << column << "," << row << ") clicked" << std::endl;

              std::vector<ItemStack>& containerItems = grid.getContainer()->getItems();
              ItemStack* cursorItemStack = cursor.getItemStack();

              if (index >= containerItems.size())  // empty slot
              {
                  if (cursorItemStack == nullptr) {
                      return;
                  }

                  grid.getContainer()->addItem(cursorItemStack->getType(),
                                               cursorItemStack->getAmount());
                  cursor.setItemStack(nullptr);
              } else {  // slot with items
                  // Beware memory leaks, when we remove item from container, we need to delete it
                  ItemStack* containerItemStackCopy = new ItemStack(containerItems[index]);

                  std::cout << "Item stack: "
                            << inventoryItemTypeToString(containerItemStackCopy->getType()) << " "
                            << containerItemStackCopy->getAmount() << std::endl;
                  std::cout << "Cursor item stack: "
                            << (cursorItemStack == nullptr
                                    ? "null"
                                    : inventoryItemTypeToString(cursorItemStack->getType()))
                            << std::endl;

                  cursor.setItemStack(containerItemStackCopy);
                  grid.getContainer()->removeItem(containerItemStackCopy->getType(),
                                                  containerItemStackCopy->getAmount());
                  if (cursorItemStack != nullptr) {  // give to cursor
                      grid.getContainer()->addItem(cursorItemStack->getType(),
                                                   cursorItemStack->getAmount());
                  }
              }

              grid.getContainer()->updateItems();
          },
          /* onRender= */
          [this, index, &grid](SceneNode& node, sf::RenderWindow& window,
                               sf::Vector2f absolutePos) {
              sf::RectangleShape itemRect;
              itemRect.setPosition(absolutePos);
              itemRect.setSize(size);
              itemRect.setFillColor(sf::Color(0, 0, 0, 0));
              itemRect.setOutlineColor(sf::Color(40, 40, 40, 255));
              itemRect.setOutlineThickness(1.0);
              window.draw(itemRect);

              std::vector<ItemStack>& items = grid.getContainer()->getItems();
              if (index >= items.size()) {
                  return;
              }
              ItemStack* itemStack = &items[index];
              int count = itemStack->getAmount();

              sf::Sprite sprite =
                  *GameResources::getInstance().getInventorySprite(itemStack->getType());
              sprite.setPosition(absolutePos);
              window.draw(sprite);

              sf::Font font = *GameResources::getInstance().getFont("main");
              sf::Text text;
              text.setFont(font);
              text.setString(std::to_string(count));
              int textWidth = 12;  // TODO: infer dynamically
              int textHeight = 12;
              text.setCharacterSize(textHeight);
              text.setFillColor(sf::Color::White);
              text.setPosition(absolutePos.x + GRID_SIZE - textWidth,
                               absolutePos.y + GRID_SIZE - textHeight);  // TODO: separate class?
              window.draw(text);
          }) {}
