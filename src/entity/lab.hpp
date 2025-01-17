#pragma once

#include "../config/recipe_configuration.hpp"
#include "../container.hpp"
#include "../entity.hpp"
#include "../scene_node.hpp"
#include "../ui/gui.hpp"

class Lab : public Entity {
   public:
    Lab(Gui &gui, sf::Vector2f pos);

   private:
    Gui &gui;
    Container *container;
    /** Ticks remaining until one unit is researched. */
    int researchUnitTicksRemaining;
    void onTick() override;
    bool isResearching;
};
