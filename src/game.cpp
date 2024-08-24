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
#include "panel.hpp"
#include "recipe_configuration.hpp"
#include "recipe_grid_slot.hpp"
#include "inventory_slot.hpp"
#include "cursor.hpp"
#include "recipe_tab.hpp"
#include "recipe_tab_type.hpp"
#include "environment.hpp"
#include "cursor_display.hpp"
#include "scene_node.hpp"
#include "item_stack.hpp"
#include "spatial_index.hpp"
#include "inventory_grid.hpp"
#include "gui.hpp"
#include "recipe_panel.hpp"
#include "button.hpp"

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

    unique_ptr<SceneNode> root(new SceneNode(
        sf::Vector2f(0, 0),
        sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT),
        /* onClick= */ nullptr,
        /* onRender= */ nullptr
    ));
    root->addChild(background.get());

    unique_ptr<Environment> environment(new Environment());
    environment->initResourcePatches(*root);

    // Panel for showing two inventory grids - e.g. player inventory and chest inventory.
    // Hidden by default.
    unique_ptr<Panel> doubleInventoryGridPanel(new Panel(
        /* position= */ sf::Vector2f(INVENTORY_H_MARGIN, INVENTORY_V_MARGIN),
        /* size= */ sf::Vector2f(
            INVENTORY_WIDTH * 2 + INVENTORY_PADDING * 3,
            INVENTORY_HEIGHT + INVENTORY_PADDING * 2
        ),
        /* fillColor= */ sf::Color(120, 120, 120, 255),
        /* visible= */ false
        ));

    // Panel for showing the crafting screen.
    unique_ptr<Panel> craftingPanel(new Panel(
        /* position= */ sf::Vector2f(INVENTORY_H_MARGIN, INVENTORY_V_MARGIN),
        /* size= */ sf::Vector2f(
            INVENTORY_WIDTH * 2 + INVENTORY_PADDING * 3,
            INVENTORY_HEIGHT + INVENTORY_PADDING * 2
        ),
        /* fillColor= */ sf::Color(120, 120, 120, 255),
        /* visible= */ false
        ));

    unique_ptr<Panel> researchPanel(new Panel(
        /* position= */ sf::Vector2f(INVENTORY_H_MARGIN, INVENTORY_V_MARGIN),
        /* size= */ sf::Vector2f(
            INVENTORY_WIDTH * 2 + INVENTORY_PADDING * 3,
            INVENTORY_HEIGHT + INVENTORY_PADDING * 2
        ),
        /* fillColor= */ sf::Color(120, 120, 120, 255),
        /* visible= */ false
        ));

    unique_ptr<Panel> escapeMenuPanel(new Panel(
        /* position= */ sf::Vector2f(ESCAPE_MENU_LEFT, ESCAPE_MENU_TOP),
        /* size= */ sf::Vector2f(ESCAPE_MENU_WIDTH, ESCAPE_MENU_HEIGHT),
        /* fillColor= */ sf::Color(120, 120, 120, 255),
        /* visible= */ false
        ));

    root->addChild(doubleInventoryGridPanel.get());
    root->addChild(craftingPanel.get());
    root->addChild(researchPanel.get());
    root->addChild(escapeMenuPanel.get());

    unique_ptr<Gui> gui(new Gui(*doubleInventoryGridPanel, *craftingPanel, *researchPanel, *escapeMenuPanel));

    unique_ptr<Button> resumeButton(new Button(
            /* position= */ sf::Vector2f(ESCAPE_MENU_ITEM_PADDING, ESCAPE_MENU_ITEM_PADDING),
            /* size= */ sf::Vector2f(ESCAPE_MENU_ITEM_WIDTH, ESCAPE_MENU_ITEM_HEIGHT),
            /* fillColor= */ sf::Color(80, 80, 80, 255),
            /* textString= */ "Resume",
            /* onClick= */ [&gui](Cursor &cursor) {
                gui->closeOpenPanels();
            }
        )
    );

    unique_ptr<Button> quitButton(new Button(
            /* position= */ sf::Vector2f(ESCAPE_MENU_ITEM_PADDING, ESCAPE_MENU_ITEM_PADDING * 2 + ESCAPE_MENU_ITEM_HEIGHT),
            /* size= */ sf::Vector2f(ESCAPE_MENU_ITEM_WIDTH, ESCAPE_MENU_ITEM_HEIGHT),
            /* fillColor= */ sf::Color(200, 80, 80, 255),
            /* textString= */ "Quit game",
            /* onClick= */ [&window](Cursor &cursor) {
                window.close();
            }
        )
    );

    escapeMenuPanel->addChild(resumeButton.get());
    escapeMenuPanel->addChild(quitButton.get());

    unique_ptr<Chest> chest(new Chest(*gui, 10, sf::Vector2f(2 * GRID_SIZE, 2 * GRID_SIZE)));
    chest->addItem(InventoryItemType::STONE_FURNACE, 2);
    chest->addItem(InventoryItemType::IRON_PLATE, 5);
    chest->updateItems();
    root->addChild(chest.get());

    unique_ptr<InventoryGrid> inventoryLeft(new InventoryGrid(sf::Vector2f(INVENTORY_PADDING, INVENTORY_PADDING), player.get()));
    unique_ptr<InventoryGrid> inventoryRight(new InventoryGrid(sf::Vector2f(INVENTORY_WIDTH + INVENTORY_PADDING * 2, INVENTORY_PADDING), chest.get() /* TODO: nullptr */));
    doubleInventoryGridPanel.get()->addChild(inventoryLeft.get());
    doubleInventoryGridPanel.get()->addChild(inventoryRight.get());
    craftingPanel.get()->addChild(inventoryLeft.get());

    unique_ptr<Cursor> cursor(new Cursor());
    unique_ptr<CursorDisplay> cursorDisplay(new CursorDisplay(*cursor));

    for (int row = 0; row < INVENTORY_HEIGHT_CELLS; row++)
    {
        for (int column = 0; column < INVENTORY_WIDTH_CELLS; column++)
        {
            int index = row * INVENTORY_WIDTH_CELLS + column;
            inventoryLeft.get()->addChild(new InventorySlot(row, column, index, *inventoryLeft));
            inventoryRight.get()->addChild(new InventorySlot(row, column, index, *inventoryRight));
        }
    }

    unique_ptr<RecipePanel> recipePanel(new RecipePanel(
        /* position= */ sf::Vector2f(INVENTORY_WIDTH + INVENTORY_PADDING * 2, INVENTORY_PADDING)
    ));
    unique_ptr<RecipeTab> logisticsTab(new RecipeTab(0, RecipeTabType::LOGISTICS, *recipePanel));
    unique_ptr<RecipeTab> productionTab(new RecipeTab(1, RecipeTabType::PRODUCTION, *recipePanel));
    unique_ptr<RecipeTab> intermediateProductsTab(new RecipeTab(2, RecipeTabType::INTERMEDIATE_PRODUCTS, *recipePanel));
    unique_ptr<RecipeTab> combatTab(new RecipeTab(3, RecipeTabType::COMBAT, *recipePanel));

    craftingPanel.get()->addChild(recipePanel.get());
    recipePanel.get()->addChild(logisticsTab.get());
    recipePanel.get()->addChild(productionTab.get());
    recipePanel.get()->addChild(intermediateProductsTab.get());
    recipePanel.get()->addChild(combatTab.get());

    unique_ptr<RecipeConfiguration> recipeConfiguration(new RecipeConfiguration());
    for (int row = 0; row < RECIPE_GRID_HEIGHT_CELLS; row++)
    {
        for (int column = 0; column < RECIPE_GRID_WIDTH_CELLS; column++)
        {
            RecipePosition* logisticsPosition = new RecipePosition(RecipeTabType::LOGISTICS, row, column);
            RecipePosition* productionPosition = new RecipePosition(RecipeTabType::PRODUCTION, row, column);
            RecipePosition* intermediateProductsPosition = new RecipePosition(RecipeTabType::INTERMEDIATE_PRODUCTS, row, column);
            RecipePosition* combatPosition = new RecipePosition(RecipeTabType::COMBAT, row, column);

            recipePanel.get()->addChild(new RecipeGridSlot(*gui, *recipePanel, *recipeConfiguration, *logisticsPosition));
            recipePanel.get()->addChild(new RecipeGridSlot(*gui, *recipePanel, *recipeConfiguration, *productionPosition));
            recipePanel.get()->addChild(new RecipeGridSlot(*gui, *recipePanel, *recipeConfiguration, *intermediateProductsPosition));
            recipePanel.get()->addChild(new RecipeGridSlot(*gui, *recipePanel, *recipeConfiguration, *combatPosition));
        }
    }

    root->addChild(player.get());
    root->addChild(cursorDisplay.get());

    unique_ptr<Renderer> renderer(
        new Renderer(window)
    );
    unique_ptr<SpatialIndex> spatialIndex(new SpatialIndex());
    gui->setContainerInventoryGrid(inventoryRight.get());
    unique_ptr<Input> input(new Input(
        window, *player, *cursor, *gui, *spatialIndex
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
