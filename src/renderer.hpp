#pragma once

#include "SFML/Graphics.hpp"
#include "scene_node.hpp"

class Renderer {
   public:
    Renderer(sf::RenderWindow &window);
    void render(SceneNode &rootSceneNode);

   private:
    sf::RenderWindow &window;
};
