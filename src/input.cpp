#include "input.hpp"
#include "player.hpp"
#include "SFML/Graphics.hpp"
#include "config/constants.hpp"
#include "environment.hpp"
#include "resource_patch.hpp"
#include "ui/gui.hpp"
#include "spatial_index.hpp"
#include <set>
#include <iostream>

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

            // Only allow clicking each node once. This prevents bugs when the node tree is a DAG
            // (e.g. when reusing the left inventory for both the crafting and the chest panels).
            set<SceneNode*> clickedNodes;

            for (SceneNode* node : nodes)
            {
                if (node->isInteractive() && node->isTransitivelyVisible() && clickedNodes.find(node) == clickedNodes.end()){
                    // TODO: use override instead of lambda?
                    node->click(cursor);
                    clickedNodes.insert(node);
                }
            }

            cout << "Clicked " << clickedNodes.size() << " nodes" << endl;
            if (clickedNodes.size() == 0) {
                if (!gui.isAnyPanelOpen()) {
                    for (SceneNode* node : nodes) {
                        if (node->canPlaceItem()) {
                            node->click(cursor);
                            break;
                        }
                    }
                }
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

            if (event.key.code == sf::Keyboard::R) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
                    cursor.rotateAntiClockwise();
                } else {
                    cursor.rotateClockwise();
                }
            }
        }
    }
}

void Input::handleOngoingEvents() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        vector<SceneNode*> nodes = spatialIndex.nodesAt(mousePosition);

        set<SceneNode*> clickedNodes;

        for (SceneNode* node : nodes)
        {
            if (node->isTransitivelyVisible() && clickedNodes.find(node) == clickedNodes.end()){
                // Note: would need dynamic_cast if this was polymorphic (virtual functions)
                if(ResourcePatch* resourcePatch = static_cast<ResourcePatch*>(node)) {
                    resourcePatch->handleMine();
                }
                clickedNodes.insert(node);
            }
        }
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
