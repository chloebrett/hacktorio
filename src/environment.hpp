#pragma once

#include "resource_patch.hpp"
#include "player.hpp"

using namespace std;

class Environment {
    public:
    Environment();
    void initResourcePatches(Player &player, SceneNode& rootSceneNode);

    private:
    void addPatches(
        Player &player,
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
