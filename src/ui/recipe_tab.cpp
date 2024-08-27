#pragma once

#include "recipe_tab.hpp"

#include <SFML/Graphics.hpp>
#include <functional>

#include "../config/constants.hpp"
#include "../config/game_resources.hpp"
#include "../scene_node.hpp"
#include "recipe_panel.hpp"
#include "recipe_tab_type.hpp"

string RecipeTab::getName() {
    switch (static_cast<int>(this->type)) {
        case static_cast<int>(RecipeTabType::LOGISTICS):
            return "Logistics";
        case static_cast<int>(RecipeTabType::PRODUCTION):
            return "Production";
        case static_cast<int>(RecipeTabType::INTERMEDIATE_PRODUCTS):
            return "Intermediate products";
        case static_cast<int>(RecipeTabType::COMBAT):
            return "Combat";
        default:
            return "Unknown";
    }
}

RecipeTab::RecipeTab(int index, RecipeTabType type, RecipePanel &panel)
    : index(index),
      type(type),
      panel(panel),
      SceneNode(
          /* position= */
          sf::Vector2f(RECIPE_TAB_WIDTH * index, 0),
          /* size= */ sf::Vector2f(RECIPE_TAB_WIDTH, RECIPE_TAB_LIST_HEIGHT),
          /* onClick= */ [index, &panel](Cursor &cursor) { panel.setSelectedTabIndex(index); },
          /* onRender= */
          [this](SceneNode &node, sf::RenderWindow &window, sf::Vector2f absolutePos) {
              sf::RectangleShape mainRect;
              mainRect.setSize(this->size);
              mainRect.setPosition(absolutePos);

              if (this->panel.getSelectedTabIndex() == this->index) {
                  mainRect.setFillColor(sf::Color(160, 160, 160, 255));
              } else {
                  mainRect.setFillColor(sf::Color(80, 80, 80, 255));
              }
              window.draw(mainRect);

              sf::Text text;
              text.setFont(*GameResources::getInstance().getFont("main"));
              text.setCharacterSize(12);
              text.setFillColor(sf::Color::White);
              text.setString(this->getName());
              text.setPosition(absolutePos.x + 10, absolutePos.y + 10);
              window.draw(text);
          }) {}
