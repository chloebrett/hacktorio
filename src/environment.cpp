#include "environment.hpp"
#include "resource_patch.hpp"
#include "config/constants.hpp"
#include "player.hpp"
#include <vector>
#include <iostream>

using namespace std;

Environment::Environment() {
}

void Environment::addPatches(
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
) {
    for (int i = xMin; i < xMax; i++) {
        for (int j = yMin; j < yMax; j++) {
            if (rand() % 100 > probabilityPercent) {
                continue;
            }
            int amount = rand() % (amountMax - amountMin) + amountMin;
            ResourcePatch* resourcePatch = new ResourcePatch(player, sf::Vector2f(i * GRID_SIZE, j * GRID_SIZE), type, amount);
            rootSceneNode.addChild(resourcePatch);
        }
    }
}

void Environment::initResourcePatches(Player &player, SceneNode& rootSceneNode) {
    addPatches(player, rootSceneNode, ResourcePatchType::IRON, 5, 11, 7, 15, 50, 5, 10);
    addPatches(player, rootSceneNode, ResourcePatchType::COAL, 30, 40, 20, 30, 50, 5, 10);
    addPatches(player, rootSceneNode, ResourcePatchType::COPPER, 15, 18, 15, 19, 50, 5, 10);
    addPatches(player, rootSceneNode, ResourcePatchType::STONE, 4, 9, 20, 25, 50, 5, 10);
    addPatches(player, rootSceneNode, ResourcePatchType::WOOD, 20, 50, 5, 25, 3, 1, 1);
}
