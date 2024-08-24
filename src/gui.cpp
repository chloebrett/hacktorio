#pragma once

#include "panel.hpp"
#include "inventory_grid.hpp"
#include "container.hpp"
#include "gui.hpp"
#include <iostream>

using namespace std;

Gui::Gui(Panel &doubleInventoryGridPanel)
    : doubleInventoryGridPanel(doubleInventoryGridPanel), containerInventoryGrid(nullptr), targetContainer(nullptr) {}

void Gui::closeOpenPanels() {
    doubleInventoryGridPanel.setVisible(false);
    targetContainer = nullptr;
}

bool Gui::isAnyPanelOpen() {
    return doubleInventoryGridPanel.isVisible();
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
    doubleInventoryGridPanel.setVisible(true);
    targetContainer = container;
    containerInventoryGrid->setContainer(container);
}

void Gui::showPanelForInteractable() {
    // TODO
}

void Gui::setContainerInventoryGrid(InventoryGrid *containerInventoryGrid) {
    this->containerInventoryGrid = containerInventoryGrid;
}
