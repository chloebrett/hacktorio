#pragma once

#include "../research/research.hpp"
#include <vector>

using namespace std;

class ResearchConfiguration {
    public:
    ResearchConfiguration();
    Research* getResearchAtIndex(int index);

    private:
    vector<Research*> researches;
};
