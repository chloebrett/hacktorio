#pragma once

#include "research.hpp"
#include <vector>

using namespace std;

class TechnologyManager {
    public:
    TechnologyManager();
    void researchFinished(Research &research);
    void isInventoryItemAvailable(InventoryItemType &type);

    private:
    vector<Research> finishedResearch;
};
