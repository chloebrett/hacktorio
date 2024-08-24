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

Renderer::Renderer(sf::RenderWindow &window) : window(window) {}

void drawInventory(sf::RenderWindow &window, Player &player, int selectedIndex)
{
    // Left inventory
    player.updateItems();
    vector<ItemStack>& items = player.getItems();
    int size = player.getItems().size();
    for (int y = 0; y < INVENTORY_HEIGHT_CELLS; y++)
    {
        for (int x = 0; x < INVENTORY_WIDTH_CELLS; x++)
        {
            int index = y * INVENTORY_WIDTH_CELLS + x;
            if (index < items.size()) {
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
}

void Renderer::render(SceneNode &rootSceneNode)
{
    window.clear();
    rootSceneNode.render(window, sf::Vector2f(0, 0));
    window.display();
}
