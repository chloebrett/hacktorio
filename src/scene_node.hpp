#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include <vector>

using namespace std;

class SceneNode {
    public:
    SceneNode(
        sf::Vector2i position,
        sf::Vector2i size,
        std::function<void()> onClick,
        std::function<void()> onRender
    );
    sf::Vector2i getPosition();
    sf::Vector2i getSize();
    function<void()> getOnClick();
    function<void()> getOnRender();
    vector<SceneNode*> &getChildren();
    void setPosition(sf::Vector2i position);
    void setSize(sf::Vector2i size);
    void setOnClick(std::function<void()> onClick);
    void setOnRender(std::function<void()> onRender);
    void addChild(SceneNode* child);
    void removeChild(SceneNode* child);

    private:
    sf::Vector2i position;
    sf::Vector2i size;
    std::function<void()> onClick;
    std::function<void()> onRender;
    vector<SceneNode*> children;
};
