#pragma once

#include <SFML/Graphics.hpp>
#include "scene_node.hpp"
#include <functional>

using namespace std;

SceneNode::SceneNode(
    sf::Vector2f position,
    sf::Vector2f size,
    std::function<void()> onClick,
    std::function<void()> onRender
) {
    this->position = position;
    this->size = size;
    this->onClick = onClick;
    this->onRender = onRender;
    this->children = vector<SceneNode*>();
    this->zIndex = 0;
}

sf::Vector2f SceneNode::getPosition() {
    return position;
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

void SceneNode::setPosition(sf::Vector2f position) {
    this->position = position;
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
