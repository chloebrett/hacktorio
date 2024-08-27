#include "recipe_panel.hpp"

#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>

#include "../config/constants.hpp"
#include "../scene_node.hpp"

RecipePanel::RecipePanel(sf::Vector2f pos)
    : selectedTabIndex(0),
      SceneNode(
          /* position= */
          pos,
          /* size= */ sf::Vector2f(RECIPE_PANEL_WIDTH, RECIPE_PANEL_HEIGHT),
          /* onClick= */ [](Cursor &cursor) { std::cout << "Recipe panel clicked" << std::endl; },
          /* onRender= */
          [this](SceneNode &node, sf::RenderWindow &window, sf::Vector2f absolutePos) {
              sf::RectangleShape mainRect;
              mainRect.setSize(this->size);
              mainRect.setPosition(absolutePos);
              mainRect.setFillColor(sf::Color(120, 120, 120, 255));
              window.draw(mainRect);
          }) {}

int RecipePanel::getSelectedTabIndex() { return selectedTabIndex; }

void RecipePanel::setSelectedTabIndex(int index) { selectedTabIndex = index; }
