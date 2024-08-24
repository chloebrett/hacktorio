#pragma once

#include <iostream>
#include "container.hpp"
#include "chest.hpp"
#include "scene_node.hpp"
#include "SFML/Graphics.hpp"
#include "game_resources.hpp"
#include "cursor.hpp"
#include <functional>
#include <vector>
#include "constants.hpp"

Chest::Chest(int capacity, sf::Vector2f pos) : capacity(capacity), SceneNode(
    /* position= */ pos,
    /* size= */ sf::Vector2f(GRID_SIZE, GRID_SIZE),
    /* onClick= */ [](Cursor &cursor) {
        std::cout << "Chest clicked" << std::endl;
    },
    /* onRender= */ [this](
        SceneNode &node,
        sf::RenderWindow &window,
        sf::Vector2f absolutePos
    ) {
        sf::Sprite sprite = *GameResources::getInstance().getSprite("chest");
        sprite.setPosition(absolutePos);
        window.draw(sprite);
    }
) {}

int Chest::getCapacity() {
    return capacity;
}

int Chest::getFreeSpace() {
    return capacity - getTotalItemCount();
}
