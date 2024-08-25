#pragma once

#include <iostream>
#include "container.hpp"
#include "stone_furnace.hpp"
#include "entity.hpp"
#include "SFML/Graphics.hpp"
#include "config/game_resources.hpp"
#include "cursor.hpp"
#include <functional>
#include <vector>
#include "config/entity_type.hpp"
#include "config/constants.hpp"
#include "ui/gui.hpp"

StoneFurnace::StoneFurnace(Gui &gui, sf::Vector2f pos) : gui(gui), Entity(
    /* position= */ pos,
    /* size= */ sf::Vector2f(2 * GRID_SIZE, 2 * GRID_SIZE),
    /* onClick= */ [this](Cursor &cursor) {
        std::cout << "Stone furnace clicked" << std::endl;
        this->gui.showPanelForEntity(this);
    },
    /* onRender= */ [this](
        SceneNode &node,
        sf::RenderWindow &window,
        sf::Vector2f absolutePos
    ) {
        sf::Sprite sprite = *GameResources::getInstance().getEntitySprite(EntityType::STONE_FURNACE);
        sprite.setPosition(absolutePos);
        window.draw(sprite);
    }
) {}
