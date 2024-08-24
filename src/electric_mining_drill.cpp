#pragma once

#include "scene_node.hpp"
#include "electric_mining_drill.hpp"
#include "constants.hpp"
#include <SFML/Graphics.hpp>
#include "game_resources.hpp"

ElectricMiningDrill::ElectricMiningDrill(
    sf::Vector2f pos
) : SceneNode(
    /* position= */ pos,
    /* size= */ sf::Vector2f(3 * GRID_SIZE, 3 * GRID_SIZE),
    /* onClick= */ nullptr,
    /* onRender= */ [this](
        SceneNode &node,
        sf::RenderWindow &window,
        sf::Vector2f absolutePos
    ) {
        sf::Sprite sprite = *GameResources::getInstance().getSprite("entity-electric-mining-drill");
        sprite.setPosition(absolutePos);
        window.draw(sprite);
    }
) {}
