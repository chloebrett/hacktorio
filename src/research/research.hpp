#pragma once

#include "research_type.hpp"
#include <vector>
#include "../recipe.hpp"

using namespace std;

// TODO: use a struct?
class Research {
    public:
    Research(
        ResearchType type,
        string name,
        vector<Research*> &prerequisites,
        vector<Recipe*> &unlocks,
        int scienceTypeMask,
        int timePerUnit,
        int unitCount);
    ResearchType type;
    string name;
    vector<Research*> &prerequisites;
    vector<Recipe*> &unlocks;
    int scienceTypeMask;
    int timePerUnit;
    int unitCount;
};
