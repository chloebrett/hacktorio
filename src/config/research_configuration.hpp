#pragma once

#include <vector>

#include "../research/research.hpp"

using namespace std;

class ResearchConfiguration {
   public:
    ResearchConfiguration();
    Research* getResearchAtIndex(int index);

   private:
    vector<Research*> researches;
};
