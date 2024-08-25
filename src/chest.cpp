#pragma once

#include <iostream>
#include "container.hpp"
#include "chest.hpp"
#include "scene_node.hpp"
#include "SFML/Graphics.hpp"
#include "config/game_resources.hpp"
#include "cursor.hpp"
#include <functional>
#include <vector>
#include "config/constants.hpp"
#include "ui/gui.hpp"

Chest::Chest(Gui &gui, int capacity, sf::Vector2f pos) : gui(gui), capacity(capacity), SceneNode(
    /* position= */ pos,
    /* size= */ sf::Vector2f(GRID_SIZE, GRID_SIZE),
    /* onClick= */ [this](Cursor &cursor) {
        std::cout << "Chest clicked" << std::endl;
        this->gui.showPanelForContainer(this);
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
