#pragma once

#include <iostream>
#include "../container.hpp"
#include "wooden_chest.hpp"
#include "../entity.hpp"
#include <SFML/Graphics.hpp>
#include "../config/game_resources.hpp"
#include "../cursor.hpp"
#include <functional>
#include <vector>
#include "../config/constants.hpp"
#include "../ui/gui.hpp"
#include "../spatial_index.hpp"
#include "../rotation.hpp"
#include "transport_belt.hpp"

TransportBelt::TransportBelt(Gui &gui, SpatialIndex &spatialIndex, Rotation rotation, sf::Vector2f pos) :
    gui(gui), spatialIndex(spatialIndex), rotation(rotation), pos(pos), Entity(
    /* position= */ pos,
    /* size= */ sf::Vector2f(GRID_SIZE, GRID_SIZE),
    /* onClick= */ [this](Cursor &cursor) {
        std::cout << "Belt clicked" << std::endl;
        this->gui.showPanelForContainer(this);
    },
    /* onRender= */ [this](
        SceneNode &node,
        sf::RenderWindow &window,
        sf::Vector2f absolutePos
    ) {
        sf::Sprite sprite = *GameResources::getInstance().getSprite("entity-transport-belt");
        sprite.setPosition(absolutePos);
        sprite.setTextureRect(sf::IntRect(15, 19, 34, 34));
        window.draw(sprite);
    }
) {}

sf::Vector2f TransportBelt::getOutputPosition() {
    switch (rotation) {
        case Rotation::UP:
            return pos + sf::Vector2f(0, -GRID_SIZE);
        case Rotation::RIGHT:
            return pos + sf::Vector2f(GRID_SIZE, 0);
        case Rotation::DOWN:
            return pos + sf::Vector2f(0, GRID_SIZE);
        case Rotation::LEFT:
            return pos + sf::Vector2f(-GRID_SIZE, 0);
    }
}

Container* TransportBelt::getOutputContainer() {
    vector<SceneNode*> nodes = spatialIndex.nodesAt(sf::Vector2i(getOutputPosition()));
    for (SceneNode* node : nodes) {
        Container* container = dynamic_cast<Container*>(node);
        if (container != nullptr) {
            return container;
        }
    }
}
