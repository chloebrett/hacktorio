#pragma once

#include "crafting_queue.hpp"

#include <iostream>
#include <vector>

#include "item_stack.hpp"
#include "player.hpp"
#include "recipe.hpp"
#include "timer.hpp"
#include "timer_event.hpp"

using namespace std;

CraftingQueue::CraftingQueue(Player &playerInventory, Timer &timer)
    : playerInventory(playerInventory), timer(timer) {}

void CraftingQueue::queueRecipe(Recipe *recipe) {
    queue.push_back(recipe);

    if (queue.size() == 1) {
        cout << "Crafting started" << endl;
        startNextRecipe();
    }
}

void CraftingQueue::startNextRecipe() {
    if (queue.size() == 0) {
        return;
    }

    Recipe *recipe = queue.front();

    cout << "Crafting started 2" << endl;
    timer.addFutureEvent(recipe->getTime(), new TimerEvent([this, recipe]() {
                             cout << "Crafting complete" << endl;
                             queue.erase(queue.begin());

                             for (ItemStack *output : recipe->getOutputs()) {
                                 playerInventory.addItem(output->getType(), output->getAmount());
                             }
                             playerInventory.updateItems();
                             startNextRecipe();
                         }));
}
