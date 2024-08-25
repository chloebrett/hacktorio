#include "game.hpp"
#include "player.hpp"
#include "resource_patch.hpp"
#include "config/inventory_item_type.hpp"
#include "config/resource_patch_type.hpp"
#include "config/constants.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <memory>
#include "renderer.hpp"
#include "wooden_chest.hpp"
#include <vector>
#include "input.hpp"
#include "ui/panel.hpp"
#include "config/recipe_configuration.hpp"
#include "ui/recipe_grid_slot.hpp"
#include "ui/inventory_slot.hpp"
#include "cursor.hpp"
#include "ui/recipe_tab.hpp"
#include "ui/recipe_tab_type.hpp"
#include "environment.hpp"
#include "ui/cursor_display.hpp"
#include "scene_node.hpp"
#include "item_stack.hpp"
#include "spatial_index.hpp"
#include "ui/inventory_grid.hpp"
#include "ui/gui.hpp"
#include "ui/recipe_panel.hpp"
#include "ui/button.hpp"
#include "electric_mining_drill.hpp"
#include "entity_placement_manager.hpp"
#include "entity_manager.hpp"
#include "empty_space.hpp"
#include "wiring.hpp"
#include "timer.hpp"

using namespace std;

void Game::start()
{
    cout << "Starting game" << endl;

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Hacktorio");

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time timePerFrame = sf::seconds(1.0f / FRAMES_PER_SECOND);

    Wiring* wiring = new Wiring(window);
    SceneNode* root = wiring->root;
    SceneNode* background = wiring->background;
    Player* player = wiring->player;
    Gui* gui = wiring->gui;
    Panel* craftingPanel = wiring->craftingPanel;
    Panel* doubleInventoryGridPanel = wiring->doubleInventoryGridPanel;
    RecipePanel* recipePanel = wiring->recipePanel;
    InventoryGrid* inventoryLeft = wiring->inventoryLeft;
    InventoryGrid* inventoryRight = wiring->inventoryRight;
    Cursor *cursor = wiring->cursor;
    Timer *timer = wiring->timer;

    player->addItem(InventoryItemType::STONE, 100);
    player->addItem(InventoryItemType::STONE_FURNACE, 1);
    player->addItem(InventoryItemType::WOOD, 50);
    player->addItem(InventoryItemType::IRON_PLATE, 100);
    player->addItem(InventoryItemType::COPPER_PLATE, 100);
    player->addItem(InventoryItemType::IRON_ORE, 100);
    player->addItem(InventoryItemType::COPPER_ORE, 100);
    player->updateItems();

    WoodenChest* woodenChest = new WoodenChest(*gui, 10, sf::Vector2f(2 * GRID_SIZE, 2 * GRID_SIZE));
    woodenChest->addItem(InventoryItemType::STONE_FURNACE, 2);
    woodenChest->addItem(InventoryItemType::IRON_PLATE, 5);
    woodenChest->updateItems();
    root->addChild(woodenChest);

    RecipeConfiguration* recipeConfiguration = new RecipeConfiguration();
    for (int row = 0; row < RECIPE_GRID_HEIGHT_CELLS; row++)
    {
        for (int column = 0; column < RECIPE_GRID_WIDTH_CELLS; column++)
        {
            RecipePosition* logisticsPosition = new RecipePosition(RecipeTabType::LOGISTICS, row, column);
            RecipePosition* productionPosition = new RecipePosition(RecipeTabType::PRODUCTION, row, column);
            RecipePosition* intermediateProductsPosition = new RecipePosition(RecipeTabType::INTERMEDIATE_PRODUCTS, row, column);
            RecipePosition* combatPosition = new RecipePosition(RecipeTabType::COMBAT, row, column);

            recipePanel->addChild(new RecipeGridSlot(*gui, *recipePanel, *recipeConfiguration, *logisticsPosition));
            recipePanel->addChild(new RecipeGridSlot(*gui, *recipePanel, *recipeConfiguration, *productionPosition));
            recipePanel->addChild(new RecipeGridSlot(*gui, *recipePanel, *recipeConfiguration, *intermediateProductsPosition));
            recipePanel->addChild(new RecipeGridSlot(*gui, *recipePanel, *recipeConfiguration, *combatPosition));
        }
    }

    Renderer* renderer = new Renderer(window);
    SpatialIndex* spatialIndex = new SpatialIndex();
    gui->setContainerInventoryGrid(inventoryRight);
    Input* input = new Input(window, *player, *cursor, *gui, *spatialIndex);

    int currentTick;
    while (window.isOpen())
    {
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > timePerFrame)
        {
            currentTick++;
            timeSinceLastUpdate -= timePerFrame;

            spatialIndex->refresh(*root);
            timer->runEvents(currentTick);
            input->handleQueuedEvents();
            input->handleOngoingEvents();
        }

        renderer->render(*root);
    }
};
