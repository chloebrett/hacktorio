#include "entity.hpp"

#include "scene_node.hpp"

Entity::Entity(sf::Vector2f pos, sf::Vector2f size, std::function<void(Cursor&)> onClick,
               std::function<void(SceneNode&, sf::RenderWindow&, sf::Vector2f)> onRender)
    : SceneNode(pos, size, onClick, onRender) {};
