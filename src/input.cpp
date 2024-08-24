#include "input.hpp"
#include "player.hpp"
#include "SFML/Graphics.hpp"
#include "constants.hpp"
#include "environment.hpp"
#include "resource_patch.hpp"
#include "gui.hpp"
#include "spatial_index.hpp"

using namespace std;

Input::Input(
    sf::RenderWindow &window,
    Player &player,
    Cursor &cursor,
    Gui &gui,
    SpatialIndex &spatialIndex
) : window(window), player(player), cursor(cursor), gui(gui), spatialIndex(spatialIndex) {};

void Input::handleQueuedEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            vector<SceneNode*> nodes = spatialIndex.nodesAt(mousePosition);
            for (SceneNode* node : nodes)
            {
                node->click(cursor);
            }
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::E) {
                gui.showCrafting();
            } else if (event.key.code == sf::Keyboard::T) {
                gui.showResearch();
            } else if (event.key.code == sf::Keyboard::Escape) {
                if (gui.isAnyPanelOpen()) {
                    gui.closeOpenPanels();
                } else {
                    gui.showEscapeMenu();
                }
            }
        }
    }
}

void Input::handleOngoingEvents() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        // vector<ResourcePatch>& resourcePatches = environment.getResourcePatches();
        // sf::Vector2f playerPosition = player.getPos();
        // std::cout << "playerPosition: " << playerPosition.x << ", " << playerPosition.y << std::endl;
        // std::cout << "rps" << resourcePatches.size() << std::endl;
        // for (ResourcePatch& resourcePatch : resourcePatches)
        // {
        //     sf::Vector2f resourcePatchPosition = resourcePatch.getPos();
        //     sf::Vector2f diff = playerPosition - resourcePatchPosition;
        //     if (abs(diff.x) < 0.5 * GRID_SIZE && abs(diff.y) < 0.5 * GRID_SIZE)
        //     {
        //         if (resourcePatch.getRemaining() > 0)
        //         {
        //             bool didMine = resourcePatch.mine(player.getMiningSpeed() / FRAMES_PER_SECOND);
        //             std::cout << "Mined: " << didMine << std::endl;
        //             if (didMine)
        //             {
        //                 player.addItem(resourcePatch.getInventoryItemType(), 1);
        //             }
        //         }
        //     }
        // }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        player.setPos(sf::Vector2f(player.getPos().x, player.getPos().y - player.getMoveSpeed()));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        player.setPos(sf::Vector2f(player.getPos().x, player.getPos().y + player.getMoveSpeed()));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        player.setPos(sf::Vector2f(player.getPos().x - player.getMoveSpeed(), player.getPos().y));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        player.setPos(sf::Vector2f(player.getPos().x + player.getMoveSpeed(), player.getPos().y));
    }
}
