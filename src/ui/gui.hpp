#pragma once

#include "../container.hpp"
#include "../crafting_queue.hpp"
#include "../entity.hpp"
#include "../recipe.hpp"
#include "../timer.hpp"
#include "inventory_grid.hpp"
#include "panel.hpp"

/**
 * Wrappers for Gui functionality, mainly showing/hiding panels.
 */
class Gui {
   public:
    Gui(Panel &doubleInventoryGridPanel, Panel &craftingPanel, Panel &entityPanel,
        Panel &researchPanel, Panel &escapeMenuPanel, Container &playerInventory, Timer &timer,
        CraftingQueue &craftingQueue);
    void closeOpenPanels();
    void showCrafting();
    void showResearch();
    void showEscapeMenu();
    void showPanelForContainer(Container *container);
    void showPanelForEntity(Container *entity);
    void setContainerInventoryGrid(InventoryGrid *containerInventoryGrid);
    void setEntityInventoryGrid(InventoryGrid *entityInventoryGrid);
    bool isAnyPanelOpen();
    void startCraftingRecipe(Recipe *recipe);

   private:
    Panel &doubleInventoryGridPanel;
    Panel &craftingPanel;
    Panel &entityPanel;
    Panel &researchPanel;
    Panel &escapeMenuPanel;
    Timer &timer;
    Container &playerInventory;
    InventoryGrid *containerInventoryGrid;
    Container *targetContainer;
    InventoryGrid *entityInventoryGrid;
    Container *targetEntity;
    CraftingQueue &craftingQueue;
};
