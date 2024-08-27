#pragma once

#include "rotation.hpp"
#include "scene_node.hpp"

using namespace std;

class Entity : public SceneNode {
   public:
    Entity(sf::Vector2f pos, sf::Vector2f size, std::function<void(Cursor&)> onClick,
           std::function<void(SceneNode&, sf::RenderWindow&, sf::Vector2f)> onRender);

   private:
    Rotation rotation;
};
