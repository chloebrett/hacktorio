#pragma once

#include "item_stack.hpp"
#include "recipe.hpp"
#include <vector>

using namespace std;

Recipe::Recipe(
    vector<ItemStack> &inputs,
    vector<ItemStack> &outputs,
    float time
) : inputs(inputs), outputs(outputs), time(time) {}
