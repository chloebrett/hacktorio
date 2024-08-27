#pragma once

#include <vector>

#include "research.hpp"

using namespace std;

class TechnologyManager {
   public:
    TechnologyManager();
    void researchFinished(Research &research);
    void isInventoryItemAvailable(InventoryItemType &type);

   private:
    vector<Research> finishedResearch;
};
