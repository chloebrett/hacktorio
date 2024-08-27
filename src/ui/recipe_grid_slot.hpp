#pragma once

#include "../config/recipe_configuration.hpp"
#include "../scene_node.hpp"
#include "gui.hpp"
#include "recipe_panel.hpp"
#include "recipe_position.hpp"

class RecipeGridSlot : public SceneNode {
   public:
    RecipeGridSlot(Gui &gui, RecipePanel &recipePanel, RecipeConfiguration &recipeConfiguration,
                   RecipePosition &position);
    bool isVisible();

   private:
    Gui &gui;
    RecipePanel &recipePanel;
    RecipeConfiguration &recipeConfiguration;
    RecipePosition position;
};
