#pragma once

#include "panel.hpp"
#include "../config/constants.hpp"
#include <SFML/Graphics.hpp>
#include <functional>
#include "../scene_node.hpp"

Panel::Panel(sf::Vector2f position, sf::Vector2f size, sf::Color fillColor, bool visible) : SceneNode(
    /* position= */ position,
    /* size= */ size,
    /* onClick= */ nullptr,
    /* onRender= */ [this, fillColor](
        SceneNode &node,
        sf::RenderWindow &window,
        sf::Vector2f absolutePos
    ) {
        sf::RectangleShape mainRect;
        mainRect.setSize(this->size);
        mainRect.setPosition(absolutePos);
        mainRect.setFillColor(fillColor);
        window.draw(mainRect);
    }
) {
    this->setVisible(visible);
}
