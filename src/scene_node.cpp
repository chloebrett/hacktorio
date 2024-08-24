#pragma once

#include <SFML/Graphics.hpp>
#include "scene_node.hpp"
#include <functional>

using namespace std;

SceneNode::SceneNode(
    sf::Vector2f pos,
    sf::Vector2f size,
    std::function<void()> onClick,
    std::function<void()> onRender
) {
    this->pos = pos;
    this->size = size;
    this->onClick = onClick;
    this->onRender = onRender;
    this->children = vector<SceneNode*>();
    this->z = 0;
}

sf::Vector2f SceneNode::getPos() {
    return pos;
}

sf::Vector2f SceneNode::getSize() {
    return size;
}

std::function<void()> SceneNode::getOnClick() {
    return onClick;
}

std::function<void()> SceneNode::getOnRender() {
    return onRender;
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

void SceneNode::setOnClick(std::function<void()> onClick) {
    this->onClick = onClick;
}

void SceneNode::setOnRender(std::function<void()> onRender) {
    this->onRender = onRender;
}

void SceneNode::addChild(SceneNode* child) {
    children.push_back(child);
}

void SceneNode::removeChild(SceneNode* child) {
    // Find the first occurrence of child
    auto it = std::find(children.begin(), children.end(), child);

    // If the value was found, erase it
    if (it != children.end()) {
        children.erase(it);
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

void SceneNode::setVisible(bool visible) {
    this->visible = visible;
}
