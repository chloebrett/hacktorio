#pragma once

#include "electric_mining_drill.hpp"

#include <SFML/Graphics.hpp>

#include "../config/constants.hpp"
#include "../config/game_resources.hpp"
#include "../scene_node.hpp"

ElectricMiningDrill::ElectricMiningDrill(sf::Vector2f pos)
    : Entity(
          /* position= */ pos,
          /* size= */ sf::Vector2f(3 * GRID_SIZE, 3 * GRID_SIZE),
          /* onClick= */ nullptr,
          /* onRender= */
          [this](SceneNode &node, sf::RenderWindow &window, sf::Vector2f absolutePos) {
              sf::Sprite sprite =
                  *GameResources::getInstance().getSprite("entity-electric-mining-drill");
              sprite.setPosition(absolutePos);
              window.draw(sprite);
          }) {}
