#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include <vector>

using namespace std;

class SceneNode {
    public:
    SceneNode(
        sf::Vector2f position,
        sf::Vector2f size,
        std::function<void()> onClick,
        std::function<void()> onRender
    );
    sf::Vector2f getPos();
    sf::Vector2f getSize();
    function<void()> getOnClick();
    function<void()> getOnRender();
    vector<SceneNode*> &getChildren();
    int getZ();
    void setPos(sf::Vector2f position);
    void setSize(sf::Vector2f size);
    void setOnClick(std::function<void()> onClick);
    void setOnRender(std::function<void()> onRender);
    void addChild(SceneNode* child);
    void removeChild(SceneNode* child);
    void setZ(int zIndex);
    bool isVisible();
    void setVisible(bool visible);

    protected:
    sf::Vector2f pos; // top-left, relative
    sf::Vector2f size;
    std::function<void()> onClick;
    std::function<void()> onRender;
    vector<SceneNode*> children;
    int z; // relative
    bool visible = true;
};
