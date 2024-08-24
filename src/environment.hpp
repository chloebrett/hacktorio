#pragma once

#include "resource_patch.hpp"

using namespace std;

class Environment {
    public:
    Environment();
    void initResourcePatches(SceneNode& rootSceneNode);

    private:
    void addPatches(
        SceneNode& rootSceneNode,
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
