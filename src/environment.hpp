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
};
