#pragma once

#include "scene_node.hpp"
#include "empty_space.hpp"
#include <SFML/Graphics.hpp>
#include "config/constants.hpp"
#include "entity_placement_manager.hpp"

EmptySpace::EmptySpace(sf::Vector2f pos, EntityPlacementManager &entityPlacementManager) :
    entityPlacementManager(entityPlacementManager), SceneNode(
    /* position= */ pos,
    /* size= */ sf::Vector2f(GRID_SIZE, GRID_SIZE),
    /* onClick= */ [this, pos, &entityPlacementManager](Cursor &cursor) {
        ItemStack *itemStack = cursor.getItemStack();
        cout << "Cursor::handleLeftClickOnEmptySpace" << endl;
        if (itemStack != nullptr) {
            cout << "Cursor::handleLeftClickOnEmptySpace itemStack != null" << endl;
            bool success = entityPlacementManager.tryPlaceEntity(itemStack->getType(), pos);
            cout << "Cursor::handleLeftClickOnEmptySpace success: " << success << endl;
            if (success) {
                // TODO: memory leak
                if (itemStack->getAmount() == 1) {
                    cursor.setItemStack(nullptr);
                } else {
                    cursor.setItemStack(new ItemStack(itemStack->getType(), itemStack->getAmount() - 1));
                }
            }
        }
    },
    /* onRender= */ [this](
        SceneNode &node,
        sf::RenderWindow &window,
        sf::Vector2f absolutePos
    ) {
        sf::RectangleShape mainRect;
        mainRect.setSize(this->size);
        mainRect.setPosition(absolutePos);
        mainRect.setFillColor(sf::Color(255.0f, 255.0f, 255.0f, 10.0f));
        window.draw(mainRect);
    }
) {}

bool EmptySpace::canPlaceItem() {
    return true;
}
