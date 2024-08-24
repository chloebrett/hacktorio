#pragma once

#include "container.hpp"
#include "scene_node.hpp"
#include "cursor.hpp"
#include "constants.hpp"
#include "SFML/Graphics.hpp"

Cursor::Cursor() : SceneNode(
    /* position= */ sf::Vector2f(0.0, 0.0), // TODO: update position on each frame / when mouse moves
    /* size= */ sf::Vector2f(GRID_SIZE, GRID_SIZE),
    /* onClick= */ nullptr,
    /* onRender= */ [this](
        SceneNode &node,
        sf::RenderWindow &window,
        sf::Vector2f absolutePos
    ) {
        sf::RectangleShape cursorRect;
        cursorRect.setSize(sf::Vector2f(1 * GRID_SIZE, 1 * GRID_SIZE));
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        cursorRect.setPosition(mousePos.x, mousePos.y);
        cursorRect.setFillColor(sf::Color(255, 255, 255, 255));
        window.draw(cursorRect);
    }
) {}
