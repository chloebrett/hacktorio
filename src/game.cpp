#include "game.hpp"
#include "player.hpp"
#include "resource_patch.hpp"
#include "inventory_item_type.hpp"
#include "resource_patch_type.hpp"

#include "SFML/Graphics.hpp"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

std::string inventoryItemTypeToString(InventoryItemType inventoryItemType)
{
    switch (inventoryItemType)
    {
        case InventoryItemType::IIT_IRON_ORE:
            return "Iron Ore";
        case InventoryItemType::IIT_COAL:
            return "Coal";
        case InventoryItemType::IIT_COPPER_ORE:
            return "Copper Ore";
        case InventoryItemType::IIT_STONE:
            return "Stone";
        default:
            return "Unknown";
    }
}

void drawInventory(sf::RenderWindow &window, Player &player)
{
    sf::Font font;
    if (!font.loadFromFile("res/Inconsolata-Regular.ttf"))
    {
        std::cout << "Failed to load font" << std::endl;
    }

    std::vector<InventoryItemType> inventoryItemTypes;
    inventoryItemTypes.push_back(InventoryItemType::IIT_IRON_ORE);
    inventoryItemTypes.push_back(InventoryItemType::IIT_COAL);
    inventoryItemTypes.push_back(InventoryItemType::IIT_COPPER_ORE);
    inventoryItemTypes.push_back(InventoryItemType::IIT_STONE);

    for (int i = 0; i < inventoryItemTypes.size(); i++)
    {
        InventoryItemType inventoryItemType = inventoryItemTypes[i];
        int count = player.getInventoryCount(inventoryItemType);

        sf::Text inventoryText(inventoryItemTypeToString(inventoryItemType) + ": " + std::to_string(count), font);
        inventoryText.setCharacterSize(24);
        inventoryText.setFillColor(sf::Color::White);
        inventoryText.setPosition(10, 10 + 30 * (i + 1));

        window.draw(inventoryText);
    }
}

void Game::start()
{
    std::cout << "Starting game" << std::endl;

    float GRID_SIZE = 32.0f;
    float FRAMES_PER_SECOND = 60.0f;
    int SCREEN_WIDTH = 1920;
    int SCREEN_HEIGHT = 1080;
    sf::Vector2f SCREEN_SIZE = sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT);

    sf::Color blue = sf::Color(81.0f, 168.0f, 194.0f, 255.0f);
    sf::Color green = sf::Color(85.0f, 107.0f, 95.0f, 255.0f);

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Hacktorio");

    sf::RectangleShape background;
    background.setSize(SCREEN_SIZE);
    background.setPosition(0.0f, 0.0f);
    background.setFillColor(green);

    Player player;

    sf::RectangleShape playerRect;
    playerRect.setSize(sf::Vector2f(1 * GRID_SIZE, 1 * GRID_SIZE));
    playerRect.setPosition(2 * GRID_SIZE, 2 * GRID_SIZE);
    playerRect.setFillColor(blue);

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time timePerFrame = sf::seconds(1.0f / FRAMES_PER_SECOND);

    std::map<ResourcePatchType, sf::Color> resourcePatchColors;
    resourcePatchColors[ResourcePatchType::RPT_IRON] = sf::Color(80, 81, 84, 255);
    resourcePatchColors[ResourcePatchType::RPT_COAL] = sf::Color(23, 21, 16, 255);
    resourcePatchColors[ResourcePatchType::RPT_COPPER] = sf::Color(150, 104, 68, 255);
    resourcePatchColors[ResourcePatchType::RPT_STONE] = sf::Color(145, 145, 108, 255);

    std::vector<std::unique_ptr<ResourcePatch> > resourcePatches;

    // Place iron patches
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (rand() % 2 == 0)
            {
                continue;
            }
            unique_ptr<ResourcePatch> resourcePatch(new ResourcePatch());

            resourcePatch->setPosition(sf::Vector2f((5 + i) * GRID_SIZE, (7 + j) * GRID_SIZE));
            resourcePatch->init(ResourcePatchType::RPT_IRON);
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
            unique_ptr<ResourcePatch> resourcePatch(new ResourcePatch());

            resourcePatch->setPosition(sf::Vector2f((30 + i) * GRID_SIZE, (20 + j) * GRID_SIZE));
            resourcePatch->init(ResourcePatchType::RPT_COAL);
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
            unique_ptr<ResourcePatch> resourcePatch(new ResourcePatch());

            resourcePatch->setPosition(sf::Vector2f((15 + i) * GRID_SIZE, (15 + j) * GRID_SIZE));
            resourcePatch->init(ResourcePatchType::RPT_COPPER);
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
            unique_ptr<ResourcePatch> resourcePatch(new ResourcePatch());

            resourcePatch->setPosition(sf::Vector2f((4 + i) * GRID_SIZE, (20 + j) * GRID_SIZE));
            resourcePatch->init(ResourcePatchType::RPT_STONE);
            resourcePatches.push_back(std::move(resourcePatch));
        }
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > timePerFrame)
        {
            timeSinceLastUpdate -= timePerFrame;

            // Handle events

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                sf::Vector2f playerPosition = player.getPosition();
                for (const auto &resourcePatch : resourcePatches)
                {
                    sf::Vector2f resourcePatchPosition = resourcePatch->getPosition();
                    sf::Vector2f diff = playerPosition - resourcePatchPosition;
                    if (abs(diff.x) < 0.5 * GRID_SIZE && abs(diff.y) < 0.5 * GRID_SIZE)
                    {
                        if (resourcePatch->getRemaining() > 0)
                        {
                            bool didMine = resourcePatch->mine(player.getMiningSpeed() / FRAMES_PER_SECOND);
                            if (didMine)
                            {
                                player.addInventoryItem(resourcePatch->getInventoryItemType(), 1);
                            }
                        }
                    }
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                player.setPosition(sf::Vector2f(player.getPosition().x, player.getPosition().y - player.getMoveSpeed()));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                player.setPosition(sf::Vector2f(player.getPosition().x, player.getPosition().y + player.getMoveSpeed()));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                player.setPosition(sf::Vector2f(player.getPosition().x - player.getMoveSpeed(), player.getPosition().y));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                player.setPosition(sf::Vector2f(player.getPosition().x + player.getMoveSpeed(), player.getPosition().y));
            }

            playerRect.setPosition(player.getPosition());
        }

        window.clear();
        window.draw(background);
        for (const auto &resourcePatch : resourcePatches)
        {
            if (resourcePatch->getRemaining() > 0)
            {
                sf::RectangleShape resourcePatchRect;
                resourcePatchRect.setSize(sf::Vector2f(1 * GRID_SIZE, 1 * GRID_SIZE));
                sf::Vector2f resourcePatchPosition = resourcePatch->getPosition();
                resourcePatchRect.setPosition(resourcePatchPosition);
                resourcePatchRect.setFillColor(resourcePatchColors[resourcePatch->getType()]);
                window.draw(resourcePatchRect);
            }
        }
        window.draw(playerRect);
        drawInventory(window, player);
        window.display();
    }
};
