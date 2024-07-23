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

using namespace std;

std::vector<std::shared_ptr<ResourcePatch> > initResourcePatches()
{
    std::vector<std::shared_ptr<ResourcePatch> > resourcePatches;

    // Place iron patches
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (rand() % 2 == 0)
            {
                continue;
            }
            shared_ptr<ResourcePatch> resourcePatch(new ResourcePatch());

            resourcePatch->setPosition(sf::Vector2f((5 + i) * GRID_SIZE, (7 + j) * GRID_SIZE));
            int amount = rand() % 6 + 5; // 5-10 units
            resourcePatch->init(ResourcePatchType::RPT_IRON, amount);
            resourcePatches.push_back(std::move(resourcePatch));
        }
    }

    // Place coal patches
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (rand() % 2 == 0)
            {
                continue;
            }
            shared_ptr<ResourcePatch> resourcePatch(new ResourcePatch());

            resourcePatch->setPosition(sf::Vector2f((30 + i) * GRID_SIZE, (20 + j) * GRID_SIZE));
            int amount = rand() % 6 + 5; // 5-10 units
            resourcePatch->init(ResourcePatchType::RPT_COAL, amount);
            resourcePatches.push_back(std::move(resourcePatch));
        }
    }

    // Place copper patches
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (rand() % 2 == 0)
            {
                continue;
            }
            shared_ptr<ResourcePatch> resourcePatch(new ResourcePatch());

            resourcePatch->setPosition(sf::Vector2f((15 + i) * GRID_SIZE, (15 + j) * GRID_SIZE));
            int amount = rand() % 6 + 5; // 5-10 units
            resourcePatch->init(ResourcePatchType::RPT_COPPER, amount);
            resourcePatches.push_back(std::move(resourcePatch));
        }
    }

    // Place stone patches
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (rand() % 2 == 0)
            {
                continue;
            }
            shared_ptr<ResourcePatch> resourcePatch(new ResourcePatch());

            resourcePatch->setPosition(sf::Vector2f((4 + i) * GRID_SIZE, (20 + j) * GRID_SIZE));
            int amount = rand() % 6 + 5; // 5-10 units
            resourcePatch->init(ResourcePatchType::RPT_STONE, amount);
            resourcePatches.push_back(std::move(resourcePatch));
        }
    }

    // Place trees
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 20; j++) {
            if (rand() % 30 > 0) {
                continue;
            }
            shared_ptr<ResourcePatch> resourcePatch(new ResourcePatch());

            resourcePatch->setPosition(sf::Vector2f((20 + i) * GRID_SIZE, (5 + j) * GRID_SIZE));
            resourcePatch->init(ResourcePatchType::RPT_WOOD, 1);
            resourcePatches.push_back(std::move(resourcePatch));
        }
    }

    return resourcePatches;
}

void Game::start()
{
    std::cout << "Starting game" << std::endl;

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Hacktorio");

    shared_ptr<Player> player(new Player());

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time timePerFrame = sf::seconds(1.0f / FRAMES_PER_SECOND);

    std::vector<std::shared_ptr<ResourcePatch> > resourcePatches = initResourcePatches();

    Chest chest(10);
    chest.addItem(InventoryItemType::IIT_STONE_FURNACE, 2);
    chest.addItem(InventoryItemType::IIT_IRON_PLATE, 5);
    chest.setPosition(sf::Vector2f(25 * GRID_SIZE, 2 * GRID_SIZE));

    bool isInventoryOpen = false;
    int selectedInventoryItemIndex = 0;
    int selectedOtherItemIndex = 0;

    unique_ptr<Renderer> renderer(new Renderer(window, player, resourcePatches, chest));

    while (window.isOpen())
    {
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > timePerFrame)
        {
            timeSinceLastUpdate -= timePerFrame;

            // Handle events
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::I)
                    {
                        isInventoryOpen = !isInventoryOpen;
                    }
                    
                    if (event.key.code == sf::Keyboard::Down)
                    {
                        selectedInventoryItemIndex += 1;
                    }
                    if (event.key.code == sf::Keyboard::Up)
                    {
                        selectedInventoryItemIndex -= 1;
                    }
                    if (event.key.code == sf::Keyboard::U)
                    {
                        selectedOtherItemIndex -= 1;
                    }
                    if (event.key.code == sf::Keyboard::J)
                    {
                        selectedOtherItemIndex += 1;
                    }
                    if (event.key.code == sf::Keyboard::Right)
                    {
                        InventoryItemType itemType;
                        int i = 0;
                        for (auto& item : player->getContents()) {
                            if ((selectedInventoryItemIndex % player->getContents().size()) == i) {
                                itemType = item.first;
                                break;
                            }
                            i++;
                        }

                        int count = player->getItemCount(itemType);
                        if (count > 0 && chest.getFreeSpace() > 0)
                        {
                            std::cout << "Moving item from player to chest" << std::endl;
                            std::cout << chest.getFreeSpace() << std::endl;
                            player->removeItem(itemType, 1);
                            chest.addItem(itemType, 1);
                        }
                    }
                    if (event.key.code == sf::Keyboard::Left)
                    {
                        InventoryItemType itemType;
                        int i = 0;
                        for (auto& item : chest.getContents()) {
                            if ((selectedOtherItemIndex % chest.getContents().size()) == i) {
                                itemType = item.first;
                                break;
                            }
                            i++;
                        }

                        int count = chest.getItemCount(itemType);
                        if (count > 0)
                        {
                            chest.removeItem(itemType, 1);
                            player->addItem(itemType, 1);
                        }
                    }
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                sf::Vector2f playerPosition = player->getPosition();
                std::cout << "playerPosition: " << playerPosition.x << ", " << playerPosition.y << std::endl;
                std::cout << "rps" << resourcePatches.size() << std::endl;
                for (const auto &resourcePatch : resourcePatches)
                {
                    sf::Vector2f resourcePatchPosition = resourcePatch->getPosition();
                    sf::Vector2f diff = playerPosition - resourcePatchPosition;
                    std::cout << "Diff: " << diff.x << ", " << diff.y << std::endl;
                    if (abs(diff.x) < 0.5 * GRID_SIZE && abs(diff.y) < 0.5 * GRID_SIZE)
                    {
                        if (resourcePatch->getRemaining() > 0)
                        {
                            bool didMine = resourcePatch->mine(player->getMiningSpeed() / FRAMES_PER_SECOND);
                            std::cout << "Mined: " << didMine << std::endl;
                            if (didMine)
                            {
                                player->addItem(resourcePatch->getInventoryItemType(), 1);
                            }
                        }
                    }
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                player->setPosition(sf::Vector2f(player->getPosition().x, player->getPosition().y - player->getMoveSpeed()));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                player->setPosition(sf::Vector2f(player->getPosition().x, player->getPosition().y + player->getMoveSpeed()));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                player->setPosition(sf::Vector2f(player->getPosition().x - player->getMoveSpeed(), player->getPosition().y));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                player->setPosition(sf::Vector2f(player->getPosition().x + player->getMoveSpeed(), player->getPosition().y));
            }
        }

        renderer->render(isInventoryOpen, selectedInventoryItemIndex, selectedOtherItemIndex);
    }
};
