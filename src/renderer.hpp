#pragma once

#include "SFML/Graphics.hpp"
#include "scene_node.hpp"

using namespace std;

class Renderer {
   public:
    Renderer(sf::RenderWindow &window);
    void render(SceneNode &rootSceneNode);

   private:
    sf::RenderWindow &window;
};
