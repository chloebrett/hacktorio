#pragma once

#include "resource_patch_type.hpp"
#include "inventory_item_type.hpp"
#include "SFML/Graphics.hpp"
#include "scene_node.hpp"
#include <vector>
#include "spatial_index.hpp"
#include <iostream>

using namespace std;

/** Spatial index. Brute force for now, can be a quadtree later. */
SpatialIndex::SpatialIndex() {
    this->nodes = unique_ptr<vector<SceneNode*>>(new vector<SceneNode*>());
    this->absolutePositions = unique_ptr<vector<sf::Vector2f>>(new vector<sf::Vector2f>());
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

vector<SceneNode*> SpatialIndex::nodesAt(sf::Vector2i searchPosition) {
    vector<SceneNode*> result = vector<SceneNode*>();
    for (size_t i = 0; i < this->nodes->size(); i++) {
        SceneNode* node = (*nodes)[i];
        sf::Vector2f topLeft = (*absolutePositions)[i];
        sf::Vector2f bottomRight = topLeft + node->getSize();
        if (
            topLeft.x <= searchPosition.x && searchPosition.x <= bottomRight.x &&
            topLeft.y <= searchPosition.y && searchPosition.y <= bottomRight.y
        ) {
            // cout << "topLeft: " << topLeft.x << ", " << topLeft.y << endl;
            // cout << "bottomRight: " << bottomRight.x << ", " << bottomRight.y << endl;
            // cout << "searchPosition: " << searchPosition.x << ", " << searchPosition.y << endl;
            // cout << "Found node" << endl;
            result.push_back(node);
        }
    }
    return result;
}
