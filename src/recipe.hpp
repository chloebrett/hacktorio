#pragma once

#include "item_stack.hpp"
#include <vector>

using namespace std;

class Recipe {
    public:
    Recipe(vector<ItemStack> &inputs, vector<ItemStack> &outputs, float time);

    private:
    vector<ItemStack> &inputs;
    vector<ItemStack> &outputs;
    float time;
};
