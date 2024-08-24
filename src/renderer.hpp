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
    Renderer(sf::RenderWindow &window,
                Player &player,
                Environment &environment,
                Chest &chest,
             SceneNode &rootSceneNode,
             CursorState &cursorState);
    void renderScene();
    void renderGui(bool isInventoryOpen, int selectedInventoryItemIndex, int selectedOtherItemIndex, sf::Vector2i mousePosition);
    void render(bool isInventoryOpen, int selectedInventoryItemIndex, int selectedOtherItemIndex, sf::Vector2i mousePosition);

private:
    sf::RenderWindow &window;
    Player &player;
    Environment &environment;
    Chest &chest;
    SceneNode &rootSceneNode;
    sf::RectangleShape playerRect;
    CursorState &cursorState;
};
