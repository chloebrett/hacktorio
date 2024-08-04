#include "game.hpp"
#include "player.hpp"
#include "resource_patch.hpp"
#include "inventory_item_type.hpp"
#include "resource_patch_type.hpp"
#include "constants.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <memory>
#include "renderer.hpp"
#include "chest.hpp"
#include <vector>
#include "input.hpp"
#include "environment.hpp"

using namespace std;

void Game::start()
{
    cout << "Starting game" << endl;

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Hacktorio");

    unique_ptr<Player> player(new Player());

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time timePerFrame = sf::seconds(1.0f / FRAMES_PER_SECOND);

    unique_ptr<Environment> environment(new Environment());
    environment->initResourcePatches();

    unique_ptr<Chest> chest(new Chest(10));
    chest->addItem(InventoryItemType::STONE_FURNACE, 2);
    chest->addItem(InventoryItemType::IRON_PLATE, 5);
    chest->setPosition(sf::Vector2f(25 * GRID_SIZE, 2 * GRID_SIZE));

    unique_ptr<Renderer> renderer(
        new Renderer(window, *player, *environment, *chest)
    );
    unique_ptr<Input> input(new Input(
        window, *player, *chest, *environment
    ));

    while (window.isOpen())
    {
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > timePerFrame)
        {
            timeSinceLastUpdate -= timePerFrame;

            input->handleQueuedEvents();
            input->handleOngoingEvents();
        }

        renderer->render(
            input->getIsInventoryOpen(),
            input->getSelectedInventoryItemIndex(),
            input->getSelectedOtherItemIndex(),
            input->getMousePosition()
        );
    }
};
