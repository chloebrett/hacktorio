#pragma once

#include "scene_node.hpp"
#include <SFML/Graphics.hpp>

class RecipePanel : public SceneNode {
    public:
    RecipePanel(sf::Vector2f pos);
    int getSelectedTabIndex();
    void setSelectedTabIndex(int index);

    private:
    int selectedTabIndex;
};
