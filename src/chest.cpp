#pragma once

#include <iostream>
#include "container.hpp"
#include "chest.hpp"
#include "scene_node.hpp"
#include "SFML/Graphics.hpp"
#include <functional>
#include <vector>
#include "constants.hpp"

Chest::Chest(int capacity, sf::Vector2f pos) : SceneNode(
    /* position= */ pos,
    /* size= */ sf::Vector2f(GRID_SIZE, GRID_SIZE),
    /* onClick= */ []() {
        std::cout << "Chest clicked" << std::endl;
    },
    /* onRender= */ [](
        SceneNode &node,
        sf::RenderWindow &window,
        sf::Vector2f parentPos
    ) {
        sf::Texture texture;
        if (!texture.loadFromFile("data/base/graphics/entity/wooden-chest/wooden-chest.png"))
        {
            // Handle loading error
            cout << "Failed to load texture" << endl;
        }
        sf::Sprite sprite(texture);
        sprite.setPosition(parentPos + node.getPos());
        window.draw(sprite);
    }
) {
    this->capacity = capacity;
}

int Chest::getCapacity() {
    return capacity;
}

int Chest::getFreeSpace() {
    return capacity - getTotalItemCount();
}
