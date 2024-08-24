#pragma once

#include "recipe.hpp"
#include <map>
#include "recipe_position.hpp"

using namespace std;

struct cmpByRecipePosition {
    bool operator()(const RecipePosition& a, const RecipePosition& b) const {
        return a.getTabIndex() < b.getTabIndex() ||
            (a.getTabIndex() == b.getTabIndex() && a.getRow() < b.getRow()) ||
            (a.getTabIndex() == b.getTabIndex() && a.getRow() == b.getRow() && a.getColumn() < b.getColumn());
    }
};

class RecipeConfiguration {
    public:
    RecipeConfiguration();
    Recipe* getRecipeAtPosition(RecipePosition &position);

    private:
    map<RecipePosition, Recipe*, cmpByRecipePosition> recipeMap;
    map<InventoryItemType, Recipe*> recipeByOutputType;
    map<RecipePosition, InventoryItemType, cmpByRecipePosition> recipeOutputTypeByPosition;
    void initPositions();
    void initRecipes();
    void initRecipeMap();
    void initLogisticsRecipes();
    void initProductionRecipes();
    void initIntermediateProductsRecipes();
    void initCombatRecipes();
};
