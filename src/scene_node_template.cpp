#pragma once

#include "container.hpp"
#include "scene_node.hpp"
#include "scene_node_template.hpp"
#include "player.hpp"
#include "chest.hpp"
#include "constants.hpp"

SceneNodeTemplate::SceneNodeTemplate() : SceneNode(
    /* position= */ sf::Vector2f(0, 0),
    /* size= */ sf::Vector2f(GRID_SIZE, GRID_SIZE),
    /* onClick= */ nullptr,
    /* onRender= */ [this](
        SceneNode &node,
        sf::RenderWindow &window,
        sf::Vector2f parentPos
    ) {
    }
) {}
