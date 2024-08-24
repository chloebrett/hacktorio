#pragma once

#include "scene_node.hpp"

class Panel : public SceneNode {
    public:
    Panel(sf::Vector2f position, sf::Vector2f size, sf::Color color, bool visible);
};
