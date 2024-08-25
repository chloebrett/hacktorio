#pragma once

#include "panel.hpp"
#include "inventory_grid.hpp"
#include "../container.hpp"
#include "../recipe.hpp"
#include "../timer.hpp"
#include "../crafting_queue.hpp"
#include "../entity.hpp"

/**
 * Wrappers for Gui functionality, mainly showing/hiding panels.
 */
class Gui {
    public:
    Gui(Panel &doubleInventoryGridPanel, Panel &craftingPanel, Panel &researchPanel,
    Panel &escapeMenuPanel, Container &playerInventory, Timer &timer, CraftingQueue &craftingQueue);
    void closeOpenPanels();
    void showCrafting();
    void showResearch();
    void showEscapeMenu();
    void showPanelForContainer(Container *container);
    void showPanelForEntity(Entity *entity);
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
    CraftingQueue &craftingQueue;
};
