#pragma once

#include <iostream>
#include "container.hpp"
#include "chest.hpp"
#include "scene_node.hpp"
#include "SFML/Graphics.hpp"
#include <functional>
#include <vector>
#include "constants.hpp"

Chest::Chest(int capacity, sf::Vector2f pos) : capacity(capacity), SceneNode(
    /* position= */ pos,
    /* size= */ sf::Vector2f(GRID_SIZE, GRID_SIZE),
    /* onClick= */ []() {
        std::cout << "Chest clicked" << std::endl;
    },
    /* onRender= */ [this](
        SceneNode &node,
        sf::RenderWindow &window,
        sf::Vector2f absolutePos
    ) {
        sf::Texture texture;
        if (!texture.loadFromFile("data/base/graphics/entity/wooden-chest/wooden-chest.png"))
        {
            // Handle loading error
            cout << "Failed to load texture" << endl;
        }
        sf::Sprite sprite(texture);
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
