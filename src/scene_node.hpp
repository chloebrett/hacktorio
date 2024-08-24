#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include "cursor.hpp"
#include <vector>

using namespace std;

class SceneNode {
    public:
    SceneNode(
        sf::Vector2f pos,
        sf::Vector2f size,
        std::function<void(Cursor&)> onClick,
        std::function<void(SceneNode&, sf::RenderWindow&, sf::Vector2f)> onRender
    );
    sf::Vector2f getPos();
    sf::Vector2f getSize();
    vector<SceneNode*> &getChildren();
    int getZ();
    void setPos(sf::Vector2f position);
    void setSize(sf::Vector2f size);
    void setOnClick(std::function<void(Cursor&)> onClick);
    void addChild(SceneNode* child);
    void removeChild(SceneNode* child);
    void setZ(int zIndex);
    bool isVisible();
    bool isTransitivelyVisible();
    void setVisible(bool visible);
    void render(sf::RenderWindow &window, sf::Vector2f);
    void click(Cursor &cursor);
    void addParent(SceneNode* parent);
    void removeParent(SceneNode* parent);

    protected:
    sf::Vector2f pos; // top-left, relative
    sf::Vector2f size;
    std::function<void(Cursor&)> onClick;
    std::function<void(SceneNode&, sf::RenderWindow&, sf::Vector2f)> onRender;
    vector<SceneNode*> children;
    vector<SceneNode*> parents;
    int z; // relative
    bool visible = true;
};
