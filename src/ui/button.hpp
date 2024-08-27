#pragma once

#include <SFML/Graphics.hpp>
#include <functional>

#include "../scene_node.hpp"
#include "gui.hpp"

class Button : public SceneNode {
   public:
    Button(sf::Vector2f position, sf::Vector2f size, sf::Color color, std::string textString,
           std::function<void(Cursor&)> onClick);
};
