#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include <vector>

#include "cursor.hpp"

class SceneNode {
   public:
    SceneNode(sf::Vector2f pos, sf::Vector2f size, std::function<void(Cursor&)> onClick,
              std::function<void(SceneNode&, sf::RenderWindow&, sf::Vector2f)> onRender);
    sf::Vector2f getPos();
    sf::Vector2f getSize();
    std::vector<SceneNode*>& getChildren();
    int getZ();
    void setPos(sf::Vector2f position);
    void setSize(sf::Vector2f size);
    void setOnClick(std::function<void(Cursor&)> onClick);
    void addChild(SceneNode* child);
    void removeChild(SceneNode* child);
    void setZ(int zIndex);
    bool isVisible();
    bool isTransitivelyVisible();
    bool isInteractive();
    bool canPlaceItem();
    void setVisible(bool visible);
    void render(sf::RenderWindow& window, sf::Vector2f);
    void click(Cursor& cursor);
    void addParent(SceneNode* parent);
    void removeParent(SceneNode* parent);
    void tick();
    virtual void onTick();

   protected:
    sf::Vector2f pos;  // top-left, relative
    sf::Vector2f size;
    std::function<void(Cursor&)> onClick;
    std::function<void(SceneNode&, sf::RenderWindow&, sf::Vector2f)> onRender;
    std::vector<SceneNode*> children;
    std::vector<SceneNode*> parents;
    int z;  // relative
    bool visible = true;
};
