#pragma once

#include <vector>

#include "research.hpp"

class TechnologyManager {
   public:
    TechnologyManager();
    void researchFinished(Research &research);
    void isInventoryItemAvailable(InventoryItemType &type);

   private:
    std::vector<Research> finishedResearch;
};
