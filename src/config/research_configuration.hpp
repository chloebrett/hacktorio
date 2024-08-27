#pragma once

#include <vector>

#include "../research/research.hpp"

class ResearchConfiguration {
   public:
    ResearchConfiguration();
    Research* getResearchAtIndex(int index);

   private:
    std::vector<Research*> researches;
};
