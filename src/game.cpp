#include "game.hpp"
#include "player.hpp"
#include "resource_patch.hpp"
#include "inventory_item_type.hpp"
#include "resource_patch_type.hpp"
#include "constants.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <memory>
#include "chest.hpp"
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
    case InventoryItemType::IIT_WOOD:
        return "Wood";
    case InventoryItemType::IIT_IRON_PLATE:
        return "Iron Plate";
    case InventoryItemType::IIT_STEEL:
        return "Steel";
    case InventoryItemType::IIT_COPPER_PLATE:
        return "Copper Plate";
    case InventoryItemType::IIT_STONE_BRICK:
        return "Stone Brick";
    case InventoryItemType::IIT_STONE_FURNACE:
        return "Stone Furnace";
    default:
        return "Unknown";
    }
}

std::map<ResourcePatchType, sf::Color> getResourcePatchColors()
{
    std::map<ResourcePatchType, sf::Color> resourcePatchColors;
    resourcePatchColors[ResourcePatchType::RPT_IRON] = sf::Color(80, 81, 84, 255);
    resourcePatchColors[ResourcePatchType::RPT_COAL] = sf::Color(23, 21, 16, 255);
    resourcePatchColors[ResourcePatchType::RPT_COPPER] = sf::Color(150, 104, 68, 255);
    resourcePatchColors[ResourcePatchType::RPT_STONE] = sf::Color(145, 145, 108, 255);
    resourcePatchColors[ResourcePatchType::RPT_WOOD] = sf::Color(84, 64, 48, 255);
    return resourcePatchColors;
}

void drawInventory(sf::RenderWindow &window, Player &player, int selectedIndex)
{
    sf::Font font;
    if (!font.loadFromFile("res/Inconsolata-Regular.ttf"))
    {
        std::cout << "Failed to load font" << std::endl;
    }

    int i = 0;
    for (const auto &item : player.getContents())
    {
        InventoryItemType inventoryItemType = item.first;
        int count = item.second;

        sf::Text inventoryText(inventoryItemTypeToString(inventoryItemType) + ": " + std::to_string(count), font);
        inventoryText.setCharacterSize(24);
        inventoryText.setFillColor(sf::Color::White);
        inventoryText.setPosition(10, 10 + 30 * (i + 1));

        if (i == (selectedIndex % player.getContents().size()))
        {
            inventoryText.setFillColor(sf::Color::Red);
        }

        window.draw(inventoryText);
        i++;
    }
}

void drawChestContentsIfNear(sf::RenderWindow &window, Chest &chest, Player &player, int selectedIndex)
{
    sf::Font font;
    if (!font.loadFromFile("res/Inconsolata-Regular.ttf"))
    {
        std::cout << "Failed to load font" << std::endl;
    }

    sf::Vector2f playerPosition = player.getPosition();
    sf::Vector2f chestPosition = chest.getPosition();
    sf::Vector2f diff = playerPosition - chestPosition;
    if (abs(diff.x) < 2 * GRID_SIZE && abs(diff.y) < 2 * GRID_SIZE)
    {
        std::map<InventoryItemType, int> chestContents = chest.getContents();

        int i = 0;
        for (const auto &item : chestContents) // TODO: Be careful about ordering - is this deterministic?
        {
            InventoryItemType inventoryItemType = item.first;
            int count = item.second;

            sf::Text inventoryText(inventoryItemTypeToString(inventoryItemType) + ": " + std::to_string(count), font);
            inventoryText.setCharacterSize(24);
            inventoryText.setFillColor(sf::Color::White);
            inventoryText.setPosition(200, 10 + 30 * (i + 1));

            if (i == (selectedIndex % chestContents.size()))
            {
                inventoryText.setFillColor(sf::Color::Red);
            }

            window.draw(inventoryText);
            i++;
        }
    }
}

void drawChest(sf::RenderWindow &window, Chest &chest)
{
    sf::RectangleShape chestRect;
    chestRect.setSize(sf::Vector2f(1 * GRID_SIZE, 1 * GRID_SIZE));
    chestRect.setPosition(chest.getPosition());
    chestRect.setFillColor(sf::Color(0, 0, 0, 255));
    window.draw(chestRect);
}

std::vector<std::unique_ptr<ResourcePatch> > initResourcePatches()
{
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
            unique_ptr<ResourcePatch> resourcePatch(new ResourcePatch());

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
            unique_ptr<ResourcePatch> resourcePatch(new ResourcePatch());

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
            unique_ptr<ResourcePatch> resourcePatch(new ResourcePatch());

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
            unique_ptr<ResourcePatch> resourcePatch(new ResourcePatch());

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

    std::vector<std::unique_ptr<ResourcePatch> > resourcePatches = initResourcePatches();

    Chest chest(10);
    chest.addItem(InventoryItemType::IIT_STONE_FURNACE, 2);
    chest.addItem(InventoryItemType::IIT_IRON_PLATE, 5);
    chest.setPosition(sf::Vector2f(25 * GRID_SIZE, 2 * GRID_SIZE));

    bool isInventoryOpen = false;
    int selectedInventoryItemIndex = 0;
    int selectedOtherItemIndex = 0;

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
                        for (auto& item : player.getContents()) {
                            if ((selectedInventoryItemIndex % player.getContents().size()) == i) {
                                itemType = item.first;
                                break;
                            }
                            i++;
                        }

                        int count = player.getItemCount(itemType);
                        if (count > 0 && chest.getFreeSpace() > 0)
                        {
                            std::cout << "Moving item from player to chest" << std::endl;
                            std::cout << chest.getFreeSpace() << std::endl;
                            player.removeItem(itemType, 1);
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
                            player.addItem(itemType, 1);
                        }
                    }
                    std::cout << selectedInventoryItemIndex << std::endl;
                }
            }

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
                                player.addItem(resourcePatch->getInventoryItemType(), 1);
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
        std::map<ResourcePatchType, sf::Color> resourcePatchColors = getResourcePatchColors();
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
        if (isInventoryOpen) {
            drawInventory(window, player, selectedInventoryItemIndex);
        }
        drawChest(window, chest);
        drawChestContentsIfNear(window, chest, player, selectedOtherItemIndex);
        window.display();
    }
};
