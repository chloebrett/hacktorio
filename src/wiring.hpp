#pragma once

#include "scene_node.hpp"
#include "player.hpp"
#include "ui/gui.hpp"
#include "ui/panel.hpp"
#include "ui/button.hpp"
#include <SFML/Graphics.hpp>
#include "cursor.hpp"
#include "ui/recipe_panel.hpp"
#include "ui/inventory_grid.hpp"
#include "config/recipe_configuration.hpp"
#include "timer.hpp"
#include "spatial_index.hpp"

/**
 * Wires dependencies for game classes and attaches them to the scene tree.
 */
class Wiring {
    public:
    Wiring(sf::RenderWindow &window);
    SceneNode* root;
    SceneNode* background;
    Player* player;
    Panel *doubleInventoryGridPanel;
    Panel *craftingPanel;
    Panel *entityPanel;
    Panel *researchPanel;
    Panel *escapeMenuPanel;
    Gui *gui;
    Button *resumeButton;
    Button *quitButton;
    Cursor *cursor;
    RecipePanel *recipePanel;
    InventoryGrid *inventoryLeft;
    InventoryGrid *inventoryRight;
    InventoryGrid *entityRight;
    Timer *timer;
    SpatialIndex *spatialIndex;
    RecipeConfiguration *recipeConfiguration;

    void initUi(SceneNode* root, Player* player);

    private:
    sf::RenderWindow &window;
};
