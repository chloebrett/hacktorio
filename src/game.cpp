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

using namespace std;

vector<ResourcePatch*> initResourcePatches()
{
    vector<ResourcePatch*> resourcePatches;

    // Place iron patches
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (rand() % 2 == 0)
            {
                continue;
            }
            // TODO: does this get lost somehow?
            // Should it be a unique_ptr? Or just clean up when we remove the vector?
            ResourcePatch resourcePatch;
            resourcePatch.setPosition(sf::Vector2f((5 + i) * GRID_SIZE, (7 + j) * GRID_SIZE));
            int amount = rand() % 6 + 5; // 5-10 units
            resourcePatch.init(ResourcePatchType::RPT_IRON, amount);
            resourcePatches.push_back(&resourcePatch);
        }
    }

    // Place coal patches
    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j < 10; j++)
    //     {
    //         if (rand() % 2 == 0)
    //         {
    //             continue;
    //         }
    //         shared_ptr<ResourcePatch> resourcePatch(new ResourcePatch());

    //         resourcePatch->setPosition(sf::Vector2f((30 + i) * GRID_SIZE, (20 + j) * GRID_SIZE));
    //         int amount = rand() % 6 + 5; // 5-10 units
    //         resourcePatch->init(ResourcePatchType::RPT_COAL, amount);
    //         resourcePatches->push_back(move(resourcePatch));
    //     }
    // }

    // // Place copper patches
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         if (rand() % 2 == 0)
    //         {
    //             continue;
    //         }
    //         shared_ptr<ResourcePatch> resourcePatch(new ResourcePatch());

    //         resourcePatch->setPosition(sf::Vector2f((15 + i) * GRID_SIZE, (15 + j) * GRID_SIZE));
    //         int amount = rand() % 6 + 5; // 5-10 units
    //         resourcePatch->init(ResourcePatchType::RPT_COPPER, amount);
    //         resourcePatches->push_back(move(resourcePatch));
    //     }
    // }

    // // Place stone patches
    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < 5; j++)
    //     {
    //         if (rand() % 2 == 0)
    //         {
    //             continue;
    //         }
    //         shared_ptr<ResourcePatch> resourcePatch(new ResourcePatch());

    //         resourcePatch->setPosition(sf::Vector2f((4 + i) * GRID_SIZE, (20 + j) * GRID_SIZE));
    //         int amount = rand() % 6 + 5; // 5-10 units
    //         resourcePatch->init(ResourcePatchType::RPT_STONE, amount);
    //         resourcePatches->push_back(move(resourcePatch));
    //     }
    // }

    // // Place trees
    // for (int i = 0; i < 30; i++) {
    //     for (int j = 0; j < 20; j++) {
    //         if (rand() % 30 > 0) {
    //             continue;
    //         }
    //         shared_ptr<ResourcePatch> resourcePatch(new ResourcePatch());

    //         resourcePatch->setPosition(sf::Vector2f((20 + i) * GRID_SIZE, (5 + j) * GRID_SIZE));
    //         resourcePatch->init(ResourcePatchType::RPT_WOOD, 1);
    //         resourcePatches->push_back(move(resourcePatch));
    //     }
    // }

    return resourcePatches;
}

void Game::start()
{
    cout << "Starting game" << endl;

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Hacktorio");

    unique_ptr<Player> player(new Player());

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time timePerFrame = sf::seconds(1.0f / FRAMES_PER_SECOND);

    vector<ResourcePatch*> resourcePatches = initResourcePatches();

    unique_ptr<Chest> chest(new Chest(10));
    chest->addItem(InventoryItemType::IIT_STONE_FURNACE, 2);
    chest->addItem(InventoryItemType::IIT_IRON_PLATE, 5);
    chest->setPosition(sf::Vector2f(25 * GRID_SIZE, 2 * GRID_SIZE));

    unique_ptr<Renderer> renderer(
        new Renderer(window, *player, resourcePatches, *chest)
    );
    unique_ptr<Input> input(new Input(
        window, *player, *chest, resourcePatches
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

        renderer->render(input->getIsInventoryOpen(),
        input->getSelectedInventoryItemIndex(), input->getSelectedOtherItemIndex());
    }
};
