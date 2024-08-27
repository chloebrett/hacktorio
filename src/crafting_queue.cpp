#include "crafting_queue.hpp"

#include <iostream>
#include <vector>

#include "item_stack.hpp"
#include "player.hpp"
#include "recipe.hpp"
#include "timer.hpp"
#include "timer_event.hpp"

CraftingQueue::CraftingQueue(Player &playerInventory, Timer &timer)
    : playerInventory(playerInventory), timer(timer) {}

void CraftingQueue::queueRecipe(Recipe *recipe) {
    queue.push_back(recipe);

    if (queue.size() == 1) {
        std::cout << "Crafting started" << std::endl;
        startNextRecipe();
    }
}

void CraftingQueue::startNextRecipe() {
    if (queue.size() == 0) {
        return;
    }

    Recipe *recipe = queue.front();

    std::cout << "Crafting started 2" << std::endl;
    timer.addFutureEvent(recipe->getTime(), new TimerEvent([this, recipe]() {
                             std::cout << "Crafting complete" << std::endl;
                             queue.erase(queue.begin());

                             for (ItemStack *output : recipe->getOutputs()) {
                                 playerInventory.addItem(output->getType(), output->getAmount());
                             }
                             playerInventory.updateItems();
                             startNextRecipe();
                         }));
}
