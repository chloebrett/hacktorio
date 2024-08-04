#pragma once

#include "resource_patch.hpp"

using namespace std;

class Environment {
    public:
    Environment();
    void initResourcePatches();
    vector<ResourcePatch> &getResourcePatches();

    private:
    vector<ResourcePatch> resourcePatches;
    void addPatches(
        ResourcePatchType type,
        int xMin,
        int xMax,
        int yMin,
        int yMax,
        int probabilityPercent,
        int amountMin,
        int amountMax
    );
};
