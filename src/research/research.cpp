#include "research.hpp"

#include <vector>

#include "../recipe.hpp"
#include "research_type.hpp"

Research::Research(ResearchType type, std::string name, std::vector<Research *> &prerequisites,
                   std::vector<Recipe *> &unlocks, int scienceTypeMask, int timePerUnit,
                   int unitCount)
    : type(type),
      name(name),
      prerequisites(prerequisites),
      unlocks(unlocks),
      scienceTypeMask(scienceTypeMask),
      timePerUnit(timePerUnit),
      unitCount(unitCount) {}
