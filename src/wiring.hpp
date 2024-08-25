#pragma once

#include "scene_node.hpp"

/**
 * Wires dependencies for game classes and attaches them to the scene tree.
 */
class Wiring {
    public:
    Wiring();
    void init();
    SceneNode* getRoot();
    SceneNode* getBackground();
    SceneNode* getPlayer();

    private:
    SceneNode* root;
    SceneNode* background;
    SceneNode* player;
};
