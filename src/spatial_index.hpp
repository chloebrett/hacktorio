#pragma once

#include <vector>

#include "SFML/Graphics.hpp"
#include "config/inventory_item_type.hpp"
#include "config/resource_patch_type.hpp"
#include "scene_node.hpp"

using namespace std;

/** Spatial index. Brute force for now, can be a quadtree later. */
class SpatialIndex {
   public:
    SpatialIndex();
    void refresh(SceneNode &rootSceneNode);
    void traverse(SceneNode &node, sf::Vector2f absolutePosition);
    vector<SceneNode *> nodesAt(sf::Vector2i searchPosition);

   private:
    unique_ptr<vector<SceneNode *>> nodes;
    unique_ptr<vector<sf::Vector2f>> absolutePositions;
};
