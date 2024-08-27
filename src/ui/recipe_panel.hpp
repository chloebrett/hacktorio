#pragma once

#include <SFML/Graphics.hpp>

#include "../scene_node.hpp"

class RecipePanel : public SceneNode {
   public:
    RecipePanel(sf::Vector2f pos);
    int getSelectedTabIndex();
    void setSelectedTabIndex(int index);

   private:
    int selectedTabIndex;
};
