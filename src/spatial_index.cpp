#include "spatial_index.hpp"

#include <iostream>
#include <vector>

#include "SFML/Graphics.hpp"
#include "config/inventory_item_type.hpp"
#include "config/resource_patch_type.hpp"
#include "scene_node.hpp"

/** Spatial index. Brute force for now, can be a quadtree later. */
SpatialIndex::SpatialIndex() {
    this->nodes = std::unique_ptr<std::vector<SceneNode*>>(new std::vector<SceneNode*>());
    this->absolutePositions =
        std::unique_ptr<std::vector<sf::Vector2f>>(new std::vector<sf::Vector2f>());
}

void SpatialIndex::refresh(SceneNode& rootSceneNode) {
    this->nodes->clear();
    this->absolutePositions->clear();
    traverse(rootSceneNode, rootSceneNode.getPos());
}

void SpatialIndex::traverse(SceneNode& node, sf::Vector2f absolutePosition) {
    this->nodes->push_back(&node);
    this->absolutePositions->push_back(absolutePosition);
    for (SceneNode* child : node.getChildren()) {
        traverse(*child, absolutePosition + child->getPos());
    }
}

std::vector<SceneNode*> SpatialIndex::nodesAt(sf::Vector2i searchPosition) {
    std::vector<SceneNode*> result = std::vector<SceneNode*>();
    for (size_t i = 0; i < this->nodes->size(); i++) {
        SceneNode* node = (*nodes)[i];
        sf::Vector2f topLeft = (*absolutePositions)[i];
        sf::Vector2f bottomRight = topLeft + node->getSize();
        if (topLeft.x <= searchPosition.x && searchPosition.x <= bottomRight.x &&
            topLeft.y <= searchPosition.y && searchPosition.y <= bottomRight.y) {
            // std::cout << "topLeft: " << topLeft.x << ", " << topLeft.y << std::endl;
            // std::cout << "bottomRight: " << bottomRight.x << ", " << bottomRight.y << std::endl;
            // std::cout << "searchPosition: " << searchPosition.x << ", " << searchPosition.y <<
            // std::endl; std::cout << "Found node" << std::endl;
            result.push_back(node);
        }
    }
    return result;
}
