#pragma once

#include "panel.hpp"
#include "inventory_grid.hpp"
#include "container.hpp"
#include "gui.hpp"
#include <iostream>

using namespace std;

Gui::Gui(Panel &doubleInventoryGridPanel, Panel &craftingPanel, Panel &researchPanel, Panel &escapeMenuPanel) :
    doubleInventoryGridPanel(doubleInventoryGridPanel),
    craftingPanel(craftingPanel),
    researchPanel(researchPanel),
    escapeMenuPanel(escapeMenuPanel),
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

void Gui::showPanelForInteractable() {
    // TODO
}

void Gui::setContainerInventoryGrid(InventoryGrid *containerInventoryGrid) {
    this->containerInventoryGrid = containerInventoryGrid;
}
