#pragma once

#include <vector>

#include "player.hpp"
#include "recipe.hpp"
#include "timer.hpp"

using namespace std;

class CraftingQueue {
   public:
    CraftingQueue(Player &playerInventory, Timer &timer);
    void queueRecipe(Recipe *recipe);
    void startNextRecipe();

   private:
    vector<Recipe *> queue;
    Player &playerInventory;
    Timer &timer;
};
