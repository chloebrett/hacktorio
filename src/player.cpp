#include "player.hpp"

#include "scene_node.hpp"
#include "SFML/Graphics.hpp"
#include "constants.hpp"
#include <iostream>

Player::Player() : SceneNode(
    /* pos= */ sf::Vector2f(0, 0),
    /* size= */ sf::Vector2f(GRID_SIZE, GRID_SIZE),
    /* onClick= */ []() {
        std::cout << "Player clicked" << std::endl;
    },
    /* onRender= */ [](
        SceneNode &node,
        sf::RenderWindow &window,
        sf::Vector2f absolutePos
    ) {
        std::cout << "Player rendered" << std::endl;
        // sf::RectangleShape playerRect(size);
        // playerRect.setPosition(position);
        // playerRect.setFillColor(sf::Color::Green);
        // window.draw(playerRect);
    }
) {
};

int Player::getMoveSpeed() {
    return 4;
}

float Player::getMiningSpeed() {
    return 3; // Units per second
}
