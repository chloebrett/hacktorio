#include "gui.hpp"

#include <iostream>
#include <string>

#include "../config/game_resources.hpp"
#include "../container.hpp"
#include "../crafting_queue.hpp"
#include "../item_stack.hpp"
#include "../recipe.hpp"
#include "../timer.hpp"
#include "inventory_grid.hpp"
#include "panel.hpp"

Gui::Gui(Panel &doubleInventoryGridPanel, Panel &craftingPanel, Panel &entityPanel,
         Panel &researchPanel, Panel &escapeMenuPanel, Container &playerInventory, Timer &timer,
         CraftingQueue &craftingQueue)
    : doubleInventoryGridPanel(doubleInventoryGridPanel),
      craftingPanel(craftingPanel),
      entityPanel(entityPanel),
      researchPanel(researchPanel),
      escapeMenuPanel(escapeMenuPanel),
      playerInventory(playerInventory),
      timer(timer),
      craftingQueue(craftingQueue),
      containerInventoryGrid(nullptr),
      targetContainer(nullptr),
      entityInventoryGrid(nullptr),
      targetEntity(nullptr) {}

void Gui::closeOpenPanels() {
    doubleInventoryGridPanel.setVisible(false);
    craftingPanel.setVisible(false);
    entityPanel.setVisible(false);
    researchPanel.setVisible(false);
    escapeMenuPanel.setVisible(false);
    targetContainer = nullptr;
    targetEntity = nullptr;
}

bool Gui::isAnyPanelOpen() {
    return doubleInventoryGridPanel.isVisible() || craftingPanel.isVisible() ||
           entityPanel.isVisible() || researchPanel.isVisible() || escapeMenuPanel.isVisible();
}

void Gui::showCrafting() {
    closeOpenPanels();
    craftingPanel.setVisible(true);
}

void Gui::showResearch() {
    closeOpenPanels();
    researchPanel.setVisible(true);
}

void Gui::showEscapeMenu() {
    closeOpenPanels();
    escapeMenuPanel.setVisible(true);
}

void Gui::showPanelForContainer(Container *container) {
    if (containerInventoryGrid == nullptr) {
        std::cout << "Error: containerInventoryGrid is null" << std::endl;
        return;
    }

    closeOpenPanels();
    doubleInventoryGridPanel.setVisible(true);
    targetContainer = container;
    containerInventoryGrid->setContainer(container);
}

void Gui::showPanelForEntity(Container *entity) {
    if (entityInventoryGrid == nullptr) {
        std::cout << "Error: entityInventoryGrid is null" << std::endl;
        return;
    }

    closeOpenPanels();
    entityPanel.setVisible(true);
    targetEntity = entity;
    entityInventoryGrid->setContainer(entity);
}

void Gui::setContainerInventoryGrid(InventoryGrid *containerInventoryGrid) {
    this->containerInventoryGrid = containerInventoryGrid;
}

void Gui::setEntityInventoryGrid(InventoryGrid *entityInventoryGrid) {
    this->entityInventoryGrid = entityInventoryGrid;
}

// TODO: put the "startCraftingRecipe" method in the crafting queue as well
void Gui::startCraftingRecipe(Recipe *recipe) {
    GameResources &gameResources = GameResources::getInstance();
    for (ItemStack *input : recipe->getInputs()) {
        std::cout << "  " << input->count << " x "
                  << gameResources.inventoryItemTypeToKey(input->type) << std::endl;
    }
    std::cout << "Outputs: " << std::endl;
    for (ItemStack *output : recipe->getOutputs()) {
        std::cout << "  " << output->count << " x "
                  << gameResources.inventoryItemTypeToKey(output->type) << std::endl;
    }
    std::cout << "Crafting time: " << recipe->getTime() << "s" << std::endl;

    // Check if player has the required items
    for (ItemStack *input : recipe->getInputs()) {
        if (playerInventory.getItemCount(input->type) < input->count) {
            std::cout << "Player does not have enough "
                      << gameResources.inventoryItemTypeToKey(input->type) << " (had "
                      << playerInventory.getItemCount(input->type) << ", needed " << input->count
                      << ")" << std::endl;
            return;
        }
    }

    for (ItemStack *input : recipe->getInputs()) {
        playerInventory.removeItem(input->type, input->count);
    }
    playerInventory.updateItems();

    craftingQueue.queueRecipe(recipe);
}
