#pragma once

#include <string>
#include <vector>

#include "item_stack.hpp"

using namespace std;

class Recipe {
   public:
    Recipe(string name, vector<ItemStack *> &inputs, vector<ItemStack *> &outputs, float time);
    string getName() { return name; }
    vector<ItemStack *> &getInputs() { return inputs; }
    vector<ItemStack *> &getOutputs() { return outputs; }
    float getTime() { return time; }

   private:
    string name;
    vector<ItemStack *> &inputs;
    vector<ItemStack *> &outputs;
    float time;
};
