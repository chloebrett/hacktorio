#pragma once

#include "scene_node.hpp"
#include "player.hpp"
#include "renderer.hpp"
#include "wiring.hpp"
#include <SFML/Graphics.hpp>
#include <memory>
#include "config/constants.hpp"

/**
 * Wires dependencies for game classes and attaches them to the scene tree.
 */
Wiring::Wiring() {
    root = new SceneNode(
        sf::Vector2f(0, 0),
        sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT),
        /* onClick= */ nullptr,
        /* onRender= */ nullptr
    );

    background = new SceneNode(
        sf::Vector2f(0.0f, 0.0f),
        sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT),
        /* onClick= */ nullptr,
        /* onRender= */ [](SceneNode &node, sf::RenderWindow &window, sf::Vector2f parentPos) {
            sf::Color green = sf::Color(85.0f, 107.0f, 95.0f, 255.0f);
            sf::RectangleShape backgroundShape;
            backgroundShape.setSize(node.getSize());
            backgroundShape.setPosition(parentPos);
            backgroundShape.setFillColor(green);
            window.draw(backgroundShape);
        }
    );

    root->addChild(background);
}

SceneNode* Wiring::getRoot() {
    return root;
}

SceneNode* Wiring::getBackground() {
    return background;
}

SceneNode* Wiring::getPlayer() {
    return player;
}
