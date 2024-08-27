#pragma once

#include <vector>

#include "../recipe.hpp"
#include "research_type.hpp"

// TODO: use a struct?
class Research {
   public:
    Research(ResearchType type, std::string name, std::vector<Research *> &prerequisites,
             std::vector<Recipe *> &unlocks, int scienceTypeMask, int timePerUnit, int unitCount);
    ResearchType type;
    std::string name;
    std::vector<Research *> &prerequisites;
    std::vector<Recipe *> &unlocks;
    int scienceTypeMask;
    int timePerUnit;
    int unitCount;
};
