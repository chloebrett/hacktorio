#include "environment.hpp"
#include "resource_patch.hpp"
#include "constants.hpp"
#include <vector>

using namespace std;

Environment::Environment() {
}

void Environment::addPatches(
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
            ResourcePatch resourcePatch = ResourcePatch(sf::Vector2f(i * GRID_SIZE, j * GRID_SIZE));
            int amount = rand() % (amountMax - amountMin) + amountMin;
            resourcePatch.init(type, amount);
            resourcePatches.push_back(resourcePatch);
        }
    }
}

void Environment::initResourcePatches() {
    addPatches(ResourcePatchType::IRON, 5, 11, 7, 15, 50, 5, 10);
    addPatches(ResourcePatchType::COAL, 30, 40, 20, 30, 50, 5, 10);
    addPatches(ResourcePatchType::COPPER, 15, 18, 15, 19, 50, 5, 10);
    addPatches(ResourcePatchType::STONE, 4, 9, 20, 25, 50, 5, 10);
    addPatches(ResourcePatchType::WOOD, 20, 50, 5, 25, 3, 1, 1);
}

vector<ResourcePatch>& Environment::getResourcePatches() {
    return resourcePatches;
}
