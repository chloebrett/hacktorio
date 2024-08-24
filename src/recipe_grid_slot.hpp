#pragma once

#include "scene_node.hpp"
#include "recipe_position.hpp"
#include "gui.hpp"
#include "recipe_configuration.hpp"
#include "recipe_panel.hpp"

class RecipeGridSlot : public SceneNode {
    public:
    RecipeGridSlot(Gui &gui, RecipePanel &recipePanel, RecipeConfiguration &recipeConfiguration, RecipePosition &position);
    bool isVisible();

    private:
    Gui &gui;
    RecipePanel &recipePanel;
    RecipeConfiguration &recipeConfiguration;
    RecipePosition position;
};
