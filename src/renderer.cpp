#pragma once

#include "SFML/Graphics.hpp"
#include "scene_node.hpp"
#include "renderer.hpp"

Renderer::Renderer(sf::RenderWindow &window) : window(window) {}

void Renderer::render(SceneNode &rootSceneNode)
{
    window.clear();
    rootSceneNode.render(window, sf::Vector2f(0, 0));
    window.display();
}
