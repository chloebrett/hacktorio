#pragma once

#include <SFML/Graphics.hpp>

#include "../container.hpp"
#include "../entity.hpp"
#include "../rotation.hpp"
#include "../scene_node.hpp"
#include "../spatial_index.hpp"
#include "../ui/gui.hpp"

class TransportBelt : public Entity, public Container {
   public:
    TransportBelt(Gui &gui, SpatialIndex &spatialIndex, Rotation rotation, sf::Vector2f pos);
    sf::Vector2f getOutputPosition();
    Container *getOutputContainer();

   private:
    Gui &gui;
    SpatialIndex &spatialIndex;
    Rotation rotation;
    sf::Vector2f pos;  // note: this already exists on SceneNode
    Container *outputContainer;
    sf::IntRect getImageMask();
    int transferItemTicksRemaining;
    void onTick() override;
};
