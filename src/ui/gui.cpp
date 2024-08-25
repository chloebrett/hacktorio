#pragma once

#include "panel.hpp"
#include "inventory_grid.hpp"
#include "../container.hpp"
#include "gui.hpp"
#include <iostream>
#include <string>
#include "../config/game_resources.hpp"
#include "../recipe.hpp"
#include "../item_stack.hpp"
#include "../timer.hpp"
#include "../crafting_queue.hpp"

using namespace std;

Gui::Gui(Panel &doubleInventoryGridPanel,
Panel &craftingPanel, Panel &researchPanel, Panel &escapeMenuPanel, Container &playerInventory,
Timer &timer, CraftingQueue &craftingQueue) :
    doubleInventoryGridPanel(doubleInventoryGridPanel),
    craftingPanel(craftingPanel),
    researchPanel(researchPanel),
    escapeMenuPanel(escapeMenuPanel),
    playerInventory(playerInventory),
    timer(timer),
    craftingQueue(craftingQueue),
    containerInventoryGrid(nullptr), targetContainer(nullptr) {}

void Gui::closeOpenPanels() {
    doubleInventoryGridPanel.setVisible(false);
    craftingPanel.setVisible(false);
    researchPanel.setVisible(false);
    escapeMenuPanel.setVisible(false);
    targetContainer = nullptr;
}

bool Gui::isAnyPanelOpen() {
    return doubleInventoryGridPanel.isVisible() ||
        craftingPanel.isVisible() ||
        researchPanel.isVisible() ||
        escapeMenuPanel.isVisible();
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
        cout << "Error: containerInventoryGrid is null" << endl;
        return;
    }

    closeOpenPanels();
    doubleInventoryGridPanel.setVisible(true);
    targetContainer = container;
    containerInventoryGrid->setContainer(container);
}

void Gui::showPanelForEntity(Entity *entity) {
    // TODO
}

void Gui::setContainerInventoryGrid(InventoryGrid *containerInventoryGrid) {
    this->containerInventoryGrid = containerInventoryGrid;
}

// TODO: put the "startCraftingRecipe" method in the crafting queue as well
void Gui::startCraftingRecipe(Recipe *recipe) {
    cout << "Crafting recipe: " << recipe->getName() << endl;
    cout << "Inputs: " << endl;
    GameResources &gameResources = GameResources::getInstance();
    for (ItemStack* input : recipe->getInputs()) {
        cout << "  " << input->getAmount() << " x " << gameResources.inventoryItemTypeToKey(input->getType()) << endl;
    }
    cout << "Outputs: " << endl;
    for (ItemStack* output : recipe->getOutputs()) {
        cout << "  " << output->getAmount() << " x " << gameResources.inventoryItemTypeToKey(output->getType()) << endl;
    }
    cout << "Crafting time: " << recipe->getTime() << "s" << endl;

    // Check if player has the required items
    for (ItemStack* input : recipe->getInputs()) {
        if (playerInventory.getItemCount(input->getType()) < input->getAmount()) {
            cout << "Player does not have enough " << gameResources.inventoryItemTypeToKey(input->getType()) << " (had " << playerInventory.getItemCount(input->getType()) << ", needed " << input->getAmount() << ")" << endl;
            return;
        }
    }

    for (ItemStack* input : recipe->getInputs()) {
        playerInventory.removeItem(input->getType(), input->getAmount());
    }
    playerInventory.updateItems();

    craftingQueue.queueRecipe(recipe);
}
