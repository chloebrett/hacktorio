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
#include "inventory.hpp"
#include "inventory_slot.hpp"
#include "cursor.hpp"
#include "environment.hpp"
#include "cursor_state.hpp"
#include "scene_node.hpp"
#include "item_stack.hpp"
#include "inventory_left.hpp"
#include "spatial_index.hpp"
#include "inventory_right.hpp"

using namespace std;

void Game::start()
{
    cout << "Starting game" << endl;

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Hacktorio");

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time timePerFrame = sf::seconds(1.0f / FRAMES_PER_SECOND);

    unique_ptr<Player> player(new Player());
    player->addItem(InventoryItemType::STONE_FURNACE, 1);
    player->addItem(InventoryItemType::WOOD, 5);
    player->updateItems();

    unique_ptr<Chest> chest(new Chest(10, sf::Vector2f(2 * GRID_SIZE, 2 * GRID_SIZE)));
    chest->addItem(InventoryItemType::STONE_FURNACE, 2);
    chest->addItem(InventoryItemType::IRON_PLATE, 5);
    chest->updateItems();

    unique_ptr<SceneNode> background(new SceneNode(
        sf::Vector2f(0.0f, 0.0f),
        sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT),
        /* onClick= */ nullptr,
        /* onRender= */ [](SceneNode &node, sf::RenderWindow &window, sf::Vector2f parentPos) {
            sf::Color green = sf::Color(85.0f, 107.0f, 95.0f, 255.0f);
            sf::RectangleShape backgroundShape;
            backgroundShape.setSize(node.getSize());
            backgroundShape.setPosition(parentPos);
            backgroundShape.setFillColor(green);
            window.draw(backgroundShape);
        }
    ));

    unique_ptr<CursorState> cursorState(new CursorState());
    unique_ptr<SceneNode> root(new SceneNode(
        sf::Vector2f(0, 0),
        sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT),
        /* onClick= */ nullptr,
        /* onRender= */ nullptr
    ));
    root->addChild(background.get());

    unique_ptr<Environment> environment(new Environment());
    environment->initResourcePatches(*root);

    unique_ptr<Inventory> inventory(new Inventory());
    unique_ptr<InventoryLeft> inventoryLeft(new InventoryLeft(*player));
    unique_ptr<InventoryRight> inventoryRight(new InventoryRight(*chest));
    inventory.get()->addChild(inventoryLeft.get());
    inventory.get()->addChild(inventoryRight.get());

    for (int row = 0; row < INVENTORY_HEIGHT_CELLS; row++)
    {
        for (int column = 0; column < INVENTORY_WIDTH_CELLS; column++)
        {
            int index = row * INVENTORY_WIDTH_CELLS + column;
            inventoryLeft.get()->addChild(new InventorySlot(row, column, index, *player));
            inventoryRight.get()->addChild(new InventorySlot(row, column, index, *chest));
        }
    }

    unique_ptr<Cursor> cursor(new Cursor());

    root->addChild(player.get());
    root->addChild(chest.get());
    root->addChild(inventory.get());
    root->addChild(cursor.get());

    unique_ptr<Renderer> renderer(
        new Renderer(window)
    );
    unique_ptr<SpatialIndex> spatialIndex(new SpatialIndex());
    unique_ptr<Input> input(new Input(
        window, *player, *spatialIndex, *cursorState
    ));

    while (window.isOpen())
    {
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > timePerFrame)
        {
            timeSinceLastUpdate -= timePerFrame;

            spatialIndex->refresh(*root);
            input->handleQueuedEvents();
            input->handleOngoingEvents();
        }

        renderer->render(*root);
    }
};
