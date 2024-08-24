#pragma once

#include <SFML/Graphics.hpp>
#include "scene_node.hpp"
#include <functional>
#include <iostream>

using namespace std;

SceneNode::SceneNode(
    sf::Vector2f pos,
    sf::Vector2f size,
    std::function<void(Cursor&)> onClick,
    std::function<void(SceneNode&, sf::RenderWindow&, sf::Vector2f)> onRender
) {
    this->pos = pos;
    this->size = size;
    this->onClick = onClick;
    this->onRender = onRender;
    this->children = vector<SceneNode*>();
    this->parents = vector<SceneNode*>();
    this->z = 0;
}

sf::Vector2f SceneNode::getPos() {
    return pos;
}

sf::Vector2f SceneNode::getSize() {
    return size;
}

vector<SceneNode*> &SceneNode::getChildren() {
    return children;
}

void SceneNode::setPos(sf::Vector2f pos) {
    this->pos = pos;
}

void SceneNode::setSize(sf::Vector2f size) {
    this->size = size;
}

void SceneNode::setOnClick(std::function<void(Cursor&)> onClick) {
    this->onClick = onClick;
}

void SceneNode::addChild(SceneNode* child) {
    children.push_back(child);
    child->addParent(this);
}

void SceneNode::addParent(SceneNode* parent) {
    parents.push_back(parent);
}

void SceneNode::removeParent(SceneNode* parent) {
    // Find the first occurrence of parent
    auto it = std::find(parents.begin(), parents.end(), parent);

    // If the value was found, erase it
    if (it != parents.end()) {
        parents.erase(it);
        // Don't worry about removing the child reference, since we usually call this from removeChild() anyway.
    }
}

void SceneNode::removeChild(SceneNode* child) {
    // Find the first occurrence of child
    auto it = std::find(children.begin(), children.end(), child);

    // If the value was found, erase it
    if (it != children.end()) {
        children.erase(it);
        child->removeParent(this);
    }
}

int SceneNode::getZ() {
    return z;
}

void SceneNode::setZ(int z) {
    this->z = z;
}

bool SceneNode::isVisible() {
    return visible;
}

bool SceneNode::isTransitivelyVisible() {
    // Returns true if the node itself is directly visible, and at least one of its parents is transitively visible.
    // For the root node, there are no parents to check.
    if (!isVisible()) {
        return false;
    }
    for (auto& parent : parents) {
        if (parent->isTransitivelyVisible()) {
            return true;
        }
    }
    return parents.size() == 0;
}

void SceneNode::setVisible(bool visible) {
    this->visible = visible;
}

void SceneNode::render(sf::RenderWindow& window, sf::Vector2f parentPos) {
    if (isVisible()) {
        if (onRender != nullptr) {
            onRender(*this, window, parentPos + pos);
        }
        for (auto& child : children) {
            child->render(window, parentPos + pos);
        }
    }
}

void SceneNode::click(Cursor &cursor) {
    if (onClick != nullptr) {
        onClick(cursor);
    }
}
