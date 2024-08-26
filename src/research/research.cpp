#pragma once

#include "research_type.hpp"
#include <vector>
#include "../recipe.hpp"
#include "research.hpp"

using namespace std;

Research::Research(
    ResearchType type,
    string name,
    vector<Research*> &prerequisites,
    vector<Recipe*> &unlocks,
    int scienceTypeMask,
    int timePerUnit,
    int unitCount) :
    type(type),
    name(name),
    prerequisites(prerequisites),
    unlocks(unlocks),
    scienceTypeMask(scienceTypeMask),
    timePerUnit(timePerUnit),
    unitCount(unitCount) {
}
