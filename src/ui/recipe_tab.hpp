#pragma once

#include "recipe_panel.hpp"
#include "recipe_tab_type.hpp"

class RecipeTab : public SceneNode {
   public:
    RecipeTab(int index, RecipeTabType type, RecipePanel &panel);
    std::string getName();

   private:
    int index;
    RecipeTabType type;
    RecipePanel &panel;
};
