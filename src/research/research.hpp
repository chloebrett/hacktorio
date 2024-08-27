#pragma once

#include <vector>

#include "../recipe.hpp"
#include "research_type.hpp"

using namespace std;

// TODO: use a struct?
class Research {
   public:
    Research(ResearchType type, string name, vector<Research *> &prerequisites,
             vector<Recipe *> &unlocks, int scienceTypeMask, int timePerUnit, int unitCount);
    ResearchType type;
    string name;
    vector<Research *> &prerequisites;
    vector<Recipe *> &unlocks;
    int scienceTypeMask;
    int timePerUnit;
    int unitCount;
};
