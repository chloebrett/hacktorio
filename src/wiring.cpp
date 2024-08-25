#pragma once

#include "scene_node.hpp"
#include "player.hpp"
#include "renderer.hpp"
#include "wiring.hpp"
#include <SFML/Graphics.hpp>
#include <memory>
#include "environment.hpp"
#include "config/constants.hpp"
#include "empty_space.hpp"
#include "entity_placement_manager.hpp"
#include "ui/gui.hpp"
#include "ui/panel.hpp"
#include "ui/button.hpp"
#include <SFML/Graphics.hpp>
#include "ui/inventory_grid.hpp"
#include "ui/inventory_slot.hpp"
#include "ui/recipe_panel.hpp"
#include "ui/recipe_tab.hpp"
#include "ui/recipe_tab_type.hpp"
#include "ui/cursor_display.hpp"
#include "ui/recipe_panel.hpp"
#include "timer.hpp"
#include "crafting_queue.hpp"
#include "config/recipe_configuration.hpp"

/**
 * Wires dependencies for game classes and attaches them to the scene tree.
 */
Wiring::Wiring(sf::RenderWindow &window) : window(window) {
    timer = new Timer();

    recipeConfiguration = new RecipeConfiguration();

    root = new SceneNode(
        sf::Vector2f(0, 0),
        sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT),
        /* onClick= */ nullptr,
        /* onRender= */ nullptr
    );

    background = new SceneNode(
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
    );

    player = new Player();

    root->addChild(background);
    root->addChild(player);

    Environment* environment = new Environment();
    environment->initResourcePatches(*player, *root);

    initUi(root, player);
}

void Wiring::initUi(SceneNode *root, Player *player) {
    // Panel for showing two inventory grids - e.g. player inventory and chest inventory.
    // Hidden by default.
    doubleInventoryGridPanel = new Panel(
        /* position= */ sf::Vector2f(INVENTORY_H_MARGIN, INVENTORY_V_MARGIN),
        /* size= */ sf::Vector2f(
            INVENTORY_WIDTH * 2 + INVENTORY_PADDING * 3,
            INVENTORY_HEIGHT + INVENTORY_PADDING * 2
        ),
        /* fillColor= */ sf::Color(120, 120, 120, 255),
        /* visible= */ false
        );

    // Panel for interacting with an entity, e.g. mining drill.
    entityPanel = new Panel(
        /* position= */ sf::Vector2f(INVENTORY_H_MARGIN, INVENTORY_V_MARGIN),
        /* size= */ sf::Vector2f(
            INVENTORY_WIDTH * 2 + INVENTORY_PADDING * 3,
            INVENTORY_HEIGHT + INVENTORY_PADDING * 2
        ),
        /* fillColor= */ sf::Color(120, 120, 120, 255),
        /* visible= */ false
        );

    // Panel for showing the crafting screen.
    craftingPanel = new Panel(
        /* position= */ sf::Vector2f(INVENTORY_H_MARGIN, INVENTORY_V_MARGIN),
        /* size= */ sf::Vector2f(
            INVENTORY_WIDTH * 2 + INVENTORY_PADDING * 3,
            INVENTORY_HEIGHT + INVENTORY_PADDING * 2
        ),
        /* fillColor= */ sf::Color(120, 120, 120, 255),
        /* visible= */ false
        );

    researchPanel = new Panel(
        /* position= */ sf::Vector2f(INVENTORY_H_MARGIN, INVENTORY_V_MARGIN),
        /* size= */ sf::Vector2f(
            INVENTORY_WIDTH * 2 + INVENTORY_PADDING * 3,
            INVENTORY_HEIGHT + INVENTORY_PADDING * 2
        ),
        /* fillColor= */ sf::Color(120, 120, 120, 255),
        /* visible= */ false
        );

    escapeMenuPanel = new Panel(
        /* position= */ sf::Vector2f(ESCAPE_MENU_LEFT, ESCAPE_MENU_TOP),
        /* size= */ sf::Vector2f(ESCAPE_MENU_WIDTH, ESCAPE_MENU_HEIGHT),
        /* fillColor= */ sf::Color(120, 120, 120, 255),
        /* visible= */ false
        );

    CraftingQueue *craftingQueue = new CraftingQueue(*player, *timer);
    Gui* gui = new Gui(*doubleInventoryGridPanel, *craftingPanel, *entityPanel, *researchPanel, *escapeMenuPanel, *player, *timer, *craftingQueue);
    EntityPlacementManager* entityPlacementManager = new EntityPlacementManager(*root, *recipeConfiguration, *gui);

    for (int y = 0; y < SCREEN_HEIGHT_CELLS; y++) {
        for (int x = 0; x < SCREEN_WIDTH_CELLS; x++) {
            EmptySpace* emptySpace(
                new EmptySpace(sf::Vector2f(x * GRID_SIZE, y * GRID_SIZE), *entityPlacementManager));
            // TODO: make a vector of empty spaces so that all the things
            // added to root can be done at the same time.
            root->addChild(emptySpace);
        }
    }

    root->addChild(doubleInventoryGridPanel);
    root->addChild(craftingPanel);
    root->addChild(entityPanel);
    root->addChild(researchPanel);
    root->addChild(escapeMenuPanel);

    this->gui = gui;
    resumeButton = new Button(
            /* position= */ sf::Vector2f(ESCAPE_MENU_ITEM_PADDING, ESCAPE_MENU_ITEM_PADDING),
            /* size= */ sf::Vector2f(ESCAPE_MENU_ITEM_WIDTH, ESCAPE_MENU_ITEM_HEIGHT),
            /* fillColor= */ sf::Color(80, 80, 80, 255),
            /* textString= */ "Resume",
            /* onClick= */ [&gui](Cursor &cursor) {
                gui->closeOpenPanels();
            }
        );

    sf::RenderWindow& window = this->window;
    quitButton = new Button(
            /* position= */ sf::Vector2f(ESCAPE_MENU_ITEM_PADDING, ESCAPE_MENU_ITEM_PADDING * 2 + ESCAPE_MENU_ITEM_HEIGHT),
            /* size= */ sf::Vector2f(ESCAPE_MENU_ITEM_WIDTH, ESCAPE_MENU_ITEM_HEIGHT),
            /* fillColor= */ sf::Color(200, 80, 80, 255),
            /* textString= */ "Quit game",
            /* onClick= */ [&window](Cursor &cursor) {
                window.close();
            }
        );

    escapeMenuPanel->addChild(resumeButton);
    escapeMenuPanel->addChild(quitButton);

    inventoryLeft = 
        new InventoryGrid(sf::Vector2f(INVENTORY_PADDING, INVENTORY_PADDING), player);
    inventoryRight = new InventoryGrid(
        sf::Vector2f(INVENTORY_WIDTH + INVENTORY_PADDING * 2, INVENTORY_PADDING),
        /* initially null until player suggests a chest, etc. */ nullptr);

    doubleInventoryGridPanel->addChild(inventoryLeft);
    doubleInventoryGridPanel->addChild(inventoryRight);
    craftingPanel->addChild(inventoryLeft);
    entityPanel->addChild(inventoryLeft);

    // TODO: customize this to display differently for drills, furnaces, etc compared to how it
    // displays for chests.
    entityRight = new InventoryGrid(
        sf::Vector2f(INVENTORY_WIDTH + INVENTORY_PADDING * 2, INVENTORY_PADDING),
        /* initially null until player suggests a mining drill, etc. */ nullptr);
    entityPanel->addChild(entityRight);

    cursor = new Cursor();
    CursorDisplay* cursorDisplay = new CursorDisplay(*cursor);
    root->addChild(cursorDisplay);

    for (int row = 0; row < INVENTORY_HEIGHT_CELLS; row++)
    {
        for (int column = 0; column < INVENTORY_WIDTH_CELLS; column++)
        {
            int index = row * INVENTORY_WIDTH_CELLS + column;
            inventoryLeft->addChild(new InventorySlot(row, column, index, *inventoryLeft));
            inventoryRight->addChild(new InventorySlot(row, column, index, *inventoryRight));

            // First row: fuel.
            // Second row: inputs.
            // Third row: outputs.
            // TODO: make the container implement this.
            if (row < 3) {
                entityRight->addChild(new InventorySlot(row, column, index, *entityRight));
            }
        }
    }

    recipePanel = new RecipePanel(
        /* position= */ sf::Vector2f(INVENTORY_WIDTH + INVENTORY_PADDING * 2, INVENTORY_PADDING)
    );
    RecipeTab* logisticsTab = new RecipeTab(0, RecipeTabType::LOGISTICS, *recipePanel);
    RecipeTab* productionTab = new RecipeTab(1, RecipeTabType::PRODUCTION, *recipePanel);
    RecipeTab* intermediateProductsTab = new RecipeTab(2, RecipeTabType::INTERMEDIATE_PRODUCTS, *recipePanel);
    RecipeTab* combatTab = new RecipeTab(3, RecipeTabType::COMBAT, *recipePanel);

    craftingPanel->addChild(recipePanel);
    recipePanel->addChild(logisticsTab);
    recipePanel->addChild(productionTab);
    recipePanel->addChild(intermediateProductsTab);
    recipePanel->addChild(combatTab);
}
