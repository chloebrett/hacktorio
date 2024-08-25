#pragma once

#include "recipe_tab_type.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class RecipePosition {
    public:
    RecipePosition(const RecipeTabType recipeTabType, const int row, const int column) : recipeTabType(recipeTabType), row(row), column(column) {}
    const int getTabIndex() const {
        return static_cast<int>(recipeTabType);
    }
    const RecipeTabType getRecipeTabType() const {
        return recipeTabType;
    }
    const int getRow() const {
        return row;
    }
    const int getColumn() const {
        return column;
    }
    private:
    const RecipeTabType recipeTabType;
    const int row;
    const int column;
};