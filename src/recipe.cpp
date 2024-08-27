#include "recipe.hpp"

#include <string>
#include <vector>

#include "item_stack.hpp"

using namespace std;

Recipe::Recipe(string name, vector<ItemStack *> &inputs, vector<ItemStack *> &outputs, float time)
    : name(name), inputs(inputs), outputs(outputs), time(time) {}
