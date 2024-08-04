#include "environment.hpp"
#include "resource_patch.hpp"
#include "constants.hpp"

using namespace std;

Environment::Environment() {
}

void Environment::initResourcePatches() {
    // Place iron patches
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (rand() % 2 == 0)
            {
                continue;
            }
            ResourcePatch resourcePatch;
            resourcePatch.setPosition(sf::Vector2f((5 + i) * GRID_SIZE, (7 + j) * GRID_SIZE));
            int amount = rand() % 6 + 5; // 5-10 units
            resourcePatch.init(ResourcePatchType::RPT_IRON, amount);
            resourcePatches.push_back(resourcePatch);
        }
    }

    // Place coal patches
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (rand() % 2 == 0)
            {
                continue;
            }
            ResourcePatch resourcePatch;
            resourcePatch.setPosition(sf::Vector2f((30 + i) * GRID_SIZE, (20 + j) * GRID_SIZE));
            int amount = rand() % 6 + 5; // 5-10 units
            resourcePatch.init(ResourcePatchType::RPT_COAL, amount);
            resourcePatches.push_back(resourcePatch);
        }
    }

    // Place copper patches
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (rand() % 2 == 0)
            {
                continue;
            }
            ResourcePatch resourcePatch;
            resourcePatch.setPosition(sf::Vector2f((15 + i) * GRID_SIZE, (15 + j) * GRID_SIZE));
            int amount = rand() % 6 + 5; // 5-10 units
            resourcePatch.init(ResourcePatchType::RPT_COPPER, amount);
            resourcePatches.push_back(resourcePatch);
        }
    }

    // Place stone patches
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (rand() % 2 == 0)
            {
                continue;
            }
            ResourcePatch resourcePatch;
            resourcePatch.setPosition(sf::Vector2f((4 + i) * GRID_SIZE, (20 + j) * GRID_SIZE));
            int amount = rand() % 6 + 5; // 5-10 units
            resourcePatch.init(ResourcePatchType::RPT_STONE, amount);
            resourcePatches.push_back(resourcePatch);
        }
    }

    // Place trees
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 20; j++) {
            if (rand() % 30 > 0) {
                continue;
            }
            ResourcePatch resourcePatch;
            resourcePatch.setPosition(sf::Vector2f((20 + i) * GRID_SIZE, (5 + j) * GRID_SIZE));
            resourcePatch.init(ResourcePatchType::RPT_WOOD, 1);
            resourcePatches.push_back(resourcePatch);
        }
    }
}

vector<ResourcePatch>& Environment::getResourcePatches() {
    // vector<ResourcePatch*> resourcePatchesPtrs;
    // for (ResourcePatch &resourcePatch : resourcePatches) {
    //     resourcePatchesPtrs.push_back(&resourcePatch);
    // }
    // return resourcePatchesPtrs;
    return resourcePatches;
}
