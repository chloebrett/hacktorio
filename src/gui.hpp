#pragma once

#include "inventory.hpp"
#include "inventory_grid.hpp"
#include "container.hpp"

/**
 * Wrappers for Gui functionality, mainly showing/hiding panels.
 */
class Gui {
    public:
    Gui(Inventory &inventory);
    void closeOpenPanels();
    void showCrafting();
    void showResearch();
    void showEscapeMenu();
    void showPanelForContainer(Container *container);
    void showPanelForInteractable(); // TODO: implement interactable (e.g. mining drill)
    void setContainerInventoryGrid(InventoryGrid *containerInventoryGrid);
    bool isAnyPanelOpen();
    
    private:
    Inventory &inventory;
    InventoryGrid *containerInventoryGrid;
    Container *targetContainer;
};
