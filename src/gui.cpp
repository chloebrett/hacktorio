#pragma once

#include "inventory.hpp"
#include "inventory_grid.hpp"
#include "container.hpp"
#include "gui.hpp"
#include <iostream>

using namespace std;

Gui::Gui(Inventory &inventory)
    : inventory(inventory), containerInventoryGrid(nullptr), targetContainer(nullptr) {}

void Gui::closeOpenPanels() {
    inventory.setVisible(false);
    targetContainer = nullptr;
}

bool Gui::isAnyPanelOpen() {
    return inventory.isVisible();
}

void Gui::showCrafting() {
    // TODO
}

void Gui::showResearch() {
    // TODO
}

void Gui::showEscapeMenu() {
    // TODO
}

void Gui::showPanelForContainer(Container *container) {
    if (containerInventoryGrid == nullptr) {
        cout << "Error: containerInventoryGrid is null" << endl;
        return;
    }

    closeOpenPanels();
    inventory.setVisible(true);
    targetContainer = container;
    containerInventoryGrid->setContainer(container);
}

void Gui::showPanelForInteractable() {
    // TODO
}

void Gui::setContainerInventoryGrid(InventoryGrid *containerInventoryGrid) {
    this->containerInventoryGrid = containerInventoryGrid;
}
