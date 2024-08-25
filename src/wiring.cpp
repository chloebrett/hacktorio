#pragma once

#include "scene_node.hpp"
#include "player.hpp"
#include "renderer.hpp"
#include "wiring.hpp"
#include <SFML/Graphics.hpp>
#include <memory>
#include "config/constants.hpp"
#include "empty_space.hpp"
#include "entity_placement_manager.hpp"
#include "ui/gui.hpp"
#include "ui/panel.hpp"
#include "ui/button.hpp"
#include <SFML/Graphics.hpp>

/**
 * Wires dependencies for game classes and attaches them to the scene tree.
 */
Wiring::Wiring(sf::RenderWindow &window) : window(window) {
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

    unique_ptr<EntityPlacementManager> entityPlacementManager(new EntityPlacementManager(*root));

    for (int y = 0; y < SCREEN_HEIGHT_CELLS; y++) {
        for (int x = 0; x < SCREEN_WIDTH_CELLS; x++) {
            EmptySpace* emptySpace(
                new EmptySpace(sf::Vector2f(x * GRID_SIZE, y * GRID_SIZE), *entityPlacementManager));
            // TODO: make a vector of empty spaces so that all the things
            // added to root can be done at the same time.
            root->addChild(emptySpace);
        }
    }

    root->addChild(player);

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

    root->addChild(doubleInventoryGridPanel);
    root->addChild(craftingPanel);
    root->addChild(researchPanel);
    root->addChild(escapeMenuPanel);

    Gui* gui = new Gui(*doubleInventoryGridPanel, *craftingPanel, *researchPanel, *escapeMenuPanel, *player);
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
}
