#pragma once

#include <string>
#include <vector>

#include "item_stack.hpp"

class Recipe {
   public:
    Recipe(std::string name, std::vector<ItemStack *> &inputs, std::vector<ItemStack *> &outputs,
           float time);
    std::string getName() { return name; }
    std::vector<ItemStack *> &getInputs() { return inputs; }
    std::vector<ItemStack *> &getOutputs() { return outputs; }
    float getTime() { return time; }

   private:
    std::string name;
    std::vector<ItemStack *> &inputs;
    std::vector<ItemStack *> &outputs;
    float time;
};
