#pragma once

#include "container.hpp"
#include "scene_node.hpp"
#include "ui/gui.hpp"
#include "entity.hpp"
#include "config/recipe_configuration.hpp"

class StoneFurnace : public Entity {
    public:
    StoneFurnace(Gui &gui, RecipeConfiguration &recipeConfiguration, sf::Vector2f pos);

    private:
    Gui &gui;
    RecipeConfiguration &recipeConfiguration;
    Container *container;
    /** Ticks remaining until one unit is smelted. */
    int smeltUnitTicksRemaining;
    /** Ticks remaining until one unit of fuel is exhausted. */
    int fuelUnitTicksRemaining;
    void onTick() override;
    Recipe *currentRecipe;
    bool isSmelting;
};
