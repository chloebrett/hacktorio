#pragma once

#include "recipe_panel.hpp"
#include "constants.hpp"
#include <SFML/Graphics.hpp>
#include <functional>
#include "scene_node.hpp"

RecipePanel::RecipePanel(
    sf::Vector2f pos
) : SceneNode(
    /* position= */ pos,
    /* size= */ sf::Vector2f(RECIPE_PANEL_WIDTH, RECIPE_PANEL_HEIGHT),
    /* onClick= */ nullptr,
    /* onRender= */ [this](
        SceneNode &node,
        sf::RenderWindow &window,
        sf::Vector2f absolutePos
    ) {
        sf::RectangleShape mainRect;
        mainRect.setSize(this->size);
        mainRect.setPosition(absolutePos);
        mainRect.setFillColor(sf::Color(120, 120, 120, 255));
        window.draw(mainRect);
    }
) {
    this->setVisible(false);
}
