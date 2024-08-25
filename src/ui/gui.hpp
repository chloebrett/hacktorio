#pragma once

#include "panel.hpp"
#include "inventory_grid.hpp"
#include "../container.hpp"
#include "../recipe.hpp"
#include "../timer.hpp"

/**
 * Wrappers for Gui functionality, mainly showing/hiding panels.
 */
class Gui {
    public:
    Gui(Panel &doubleInventoryGridPanel, Panel &craftingPanel, Panel &researchPanel, Panel &escapeMenuPanel, Container &playerInventory, Timer &timer);
    void closeOpenPanels();
    void showCrafting();
    void showResearch();
    void showEscapeMenu();
    void showPanelForContainer(Container *container);
    void showPanelForInteractable(); // TODO: implement interactable (e.g. mining drill)
    void setContainerInventoryGrid(InventoryGrid *containerInventoryGrid);
    bool isAnyPanelOpen();
    void startCraftingRecipe(Recipe *recipe);
    
    private:
    Panel &doubleInventoryGridPanel;
    Panel &craftingPanel;
    Panel &researchPanel;
    Panel &escapeMenuPanel;
    Timer &timer;
    Container &playerInventory;
    InventoryGrid *containerInventoryGrid;
    Container *targetContainer;
};
