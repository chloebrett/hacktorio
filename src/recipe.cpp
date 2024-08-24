#pragma once

#include "item_stack.hpp"
#include "recipe.hpp"
#include <vector>
#include <string>

using namespace std;

Recipe::Recipe(
    string name,
    vector<ItemStack*> &inputs,
    vector<ItemStack*> &outputs,
    float time
) : name(name), inputs(inputs), outputs(outputs), time(time) {}
