#pragma once

#include "recipe.hpp"
#include <vector>

using namespace std;

class RecipeConfiguration {
    public:
    RecipeConfiguration();

    private:
    vector<Recipe> recipes;
};
