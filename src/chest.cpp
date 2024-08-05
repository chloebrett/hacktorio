#pragma once

#include <iostream>
#include "container.hpp"
#include "chest.hpp"
#include "scene_node.hpp"
#include "SFML/Graphics.hpp"
#include <functional>
#include <vector>
#include "constants.hpp"

Chest::Chest(int capacity, sf::Vector2f position) : SceneNode(
    /* position= */ position,
    /* size= */ sf::Vector2f(GRID_SIZE, GRID_SIZE),
    /* onClick= */ []() {
        std::cout << "Chest clicked" << std::endl;
    },
    /* onRender= */ [](
        // sf::RenderWindow &window,
        // sf::Vector2f position,
        // sf::Vector2f size
    ) {
        std::cout << "Chest rendered" << std::endl;
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
