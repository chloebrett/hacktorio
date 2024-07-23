#pragma once
#include "SFML/Graphics.hpp"
#include "player.hpp"
#include "resource_patch.hpp"
#include "chest.hpp"
#include <vector>

using namespace std;

    class Renderer
{
public:
    Renderer(sf::RenderWindow &window,
             std::shared_ptr<Player> player,
             std::vector<std::shared_ptr<ResourcePatch> > resourcePatches,
             shared_ptr<Chest> chest);
    void renderBackground();
    void renderScene();
    void renderGui(bool isInventoryOpen, int selectedInventoryItemIndex, int selectedOtherItemIndex);
    void render(bool isInventoryOpen, int selectedInventoryItemIndex, int selectedOtherItemIndex);

    private:
    sf::RenderWindow &window;
    std::shared_ptr<Player> player;
    std::vector<std::shared_ptr<ResourcePatch> > resourcePatches;
    shared_ptr<Chest> chest;
    sf::RectangleShape background;
    sf::RectangleShape playerRect;
};
