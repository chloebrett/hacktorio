#pragma once

#include <vector>

#include "SFML/Graphics.hpp"
#include "config/inventory_item_type.hpp"
#include "config/resource_patch_type.hpp"
#include "scene_node.hpp"

/** Spatial index. Brute force for now, can be a quadtree later. */
class SpatialIndex {
   public:
    SpatialIndex();
    void refresh(SceneNode &rootSceneNode);
    void traverse(SceneNode &node, sf::Vector2f absolutePosition);
    std::vector<SceneNode *> nodesAt(sf::Vector2i searchPosition);

   private:
    std::unique_ptr<std::vector<SceneNode *>> nodes;
    std::unique_ptr<std::vector<sf::Vector2f>> absolutePositions;
};
