#pragma once

#include "container.hpp"
#include "item_stack.hpp"
#include "cursor.hpp"
#include "constants.hpp"
#include "game_resources.hpp"
#include "cursor_display.hpp"
#include "scene_node.hpp"

CursorDisplay::CursorDisplay(Cursor &cursor) : cursor(cursor), SceneNode(
    /* position= */ sf::Vector2f(0, 0),
    /* size= */ sf::Vector2f(GRID_SIZE, GRID_SIZE),
    /* onClick= */ nullptr,
    /* onRender= */ [this](
        SceneNode &node,
        sf::RenderWindow &window,
        sf::Vector2f absolutePos
    ) {
        if (this->cursor.getItemStack() != nullptr) {
            // TODO: render the "inner inventory item" by reusing a class pulled out of InventorySlot.
            sf::Sprite sprite = *GameResources::getInstance().getInventorySprite(this->cursor.getItemStack()->getType());
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            sprite.setPosition(mousePosition.x - GRID_SIZE * 3/4, mousePosition.y - GRID_SIZE * 3/4);
            window.draw(sprite);
        }
    }
) {}
