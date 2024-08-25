#pragma once

#include "container.hpp"
#include "scene_node.hpp"
#include "ui/gui.hpp"
#include "entity.hpp"

class StoneFurnace : public Entity {
    public:
    StoneFurnace(Gui &gui, sf::Vector2f pos);

    private:
    Gui &gui;
    Container *container;
};
