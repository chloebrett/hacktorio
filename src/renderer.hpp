#pragma once
#include "SFML/Graphics.hpp"
#include "player.hpp"
#include "resource_patch.hpp"
#include "chest.hpp"
#include <vector>
#include "environment.hpp"

using namespace std;

    class Renderer
{
public:
    Renderer(sf::RenderWindow &window,
             Player &player,
             Environment &environment,
             Chest &chest);
    void renderBackground();
    void renderScene();
    void renderGui(bool isInventoryOpen, int selectedInventoryItemIndex, int selectedOtherItemIndex);
    void render(bool isInventoryOpen, int selectedInventoryItemIndex, int selectedOtherItemIndex);

    private:
    sf::RenderWindow &window;
    Player &player;
    Environment &environment;
    Chest &chest;
    sf::RectangleShape background;
    sf::RectangleShape playerRect;
};
