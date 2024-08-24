#pragma once
#include "SFML/Graphics.hpp"
#include "player.hpp"
#include "resource_patch.hpp"
#include "chest.hpp"
#include <vector>
#include "environment.hpp"
#include "scene_node.hpp"
#include "cursor_state.hpp"

using namespace std;

class Renderer
{
public:
    Renderer(sf::RenderWindow &window);
    void render(SceneNode &rootSceneNode);

private:
    sf::RenderWindow &window;
};
