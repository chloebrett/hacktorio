#pragma once

#include "scene_node.hpp"
#include "gui.hpp"
#include <functional>
#include <SFML/Graphics.hpp>

class Button : public SceneNode {
    public:
    Button(
        sf::Vector2f position,
        sf::Vector2f size,
        sf::Color color,
        string textString, 
        std::function<void(Cursor&)> onClick
    );
};
