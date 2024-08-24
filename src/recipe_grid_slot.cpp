#pragma once

#include "scene_node.hpp"
#include "recipe_grid_slot.hpp"
#include "constants.hpp"
#include <SFML/Graphics.hpp>
#include "recipe_position.hpp"
#include "gui.hpp"
#include "cursor.hpp"
#include <iostream>
#include "recipe.hpp"
#include "recipe_configuration.hpp"

using namespace std;

RecipeGridSlot::RecipeGridSlot(
    Gui &gui,
    RecipePanel &recipePanel,
    RecipeConfiguration &recipeConfiguration,
    RecipePosition &position
) : gui(gui), recipePanel(recipePanel), recipeConfiguration(recipeConfiguration), position(position), SceneNode(
    /* position= */ sf::Vector2f(position.getColumn() * GRID_SIZE, RECIPE_TAB_LIST_HEIGHT + position.getRow() * GRID_SIZE),
    /* size= */ sf::Vector2f(GRID_SIZE, GRID_SIZE),
    /* onClick= */ [this, &recipeConfiguration, &position, &gui](Cursor &cursor) {
        if (!isVisible()) return;

        std::cout << "RecipeGridSlot clicked" << std::endl;
        Recipe *recipe = recipeConfiguration.getRecipeAtPosition(position);

        if (recipe != nullptr) {
            std::cout << "Recipe found" << std::endl;
            gui.startCraftingRecipe(recipe);
        } else {
            std::cout << "No recipe found" << std::endl;
        }
    },
    /* onRender= */ [this](
        SceneNode &node,
        sf::RenderWindow &window,
        sf::Vector2f absolutePos
    ) {
        sf::RectangleShape itemRect;
        itemRect.setPosition(absolutePos);
        itemRect.setSize(size);
        itemRect.setFillColor(sf::Color(0, 0, 0, 0));
        itemRect.setOutlineColor(sf::Color(40, 40, 40, 255));
        itemRect.setOutlineThickness(1.0);
        window.draw(itemRect);
    }
) {}

bool RecipeGridSlot::isVisible() {
    return recipePanel.getSelectedTabIndex() == position.getTabIndex();
}