#include "recipe.hpp"

#include <string>
#include <vector>

#include "item_stack.hpp"

Recipe::Recipe(std::string name, std::vector<ItemStack *> &inputs,
               std::vector<ItemStack *> &outputs, float time)
    : name(name), inputs(inputs), outputs(outputs), time(time) {}
