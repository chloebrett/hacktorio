#pragma once

#include <iostream>
#include "../container.hpp"
#include "lab.hpp"
#include "../entity.hpp"
#include "SFML/Graphics.hpp"
#include "../config/game_resources.hpp"
#include "../cursor.hpp"
#include <functional>
#include <vector>
#include "../config/entity_type.hpp"
#include "../config/constants.hpp"
#include "../ui/gui.hpp"
#include "../config/recipe_configuration.hpp"
#include <math.h>

Lab::Lab(Gui &gui, sf::Vector2f pos) :
gui(gui), Entity(
    /* position= */ pos,
    /* size= */ sf::Vector2f(3 * GRID_SIZE, 3 * GRID_SIZE),
    /* onClick= */ [this](Cursor &cursor) {
        std::cout << "Lab clicked" << std::endl;
        this->gui.showPanelForEntity(this->container);
    },
    /* onRender= */ [this](
        SceneNode &node,
        sf::RenderWindow &window,
        sf::Vector2f absolutePos
    ) {
        sf::Sprite sprite = *GameResources::getInstance().getEntitySprite(EntityType::LAB);
        sprite.setPosition(absolutePos);
        float heightRatio = 0.88; // from looking at resource files - surprisingly not 1/sqrt(2)

        if (isResearching) {
            sprite.setTextureRect(sf::IntRect(size.x, 0, size.x, size.y * heightRatio));
        } else {
            sprite.setTextureRect(sf::IntRect(0, 0, size.x, size.y * heightRatio));
        }

        window.draw(sprite);
    }
) {
    container = new Container();
}

void Lab::onTick() {
    cout << "Researching: " << isResearching << endl;
    cout << "Ticks remaining: " << researchUnitTicksRemaining << endl;

    if (isResearching) {
        researchUnitTicksRemaining--;
    } else {
        if (container->getItemCount(InventoryItemType::AUTOMATION_SCIENCE_PACK) >= 1) {
            container->removeItem(InventoryItemType::AUTOMATION_SCIENCE_PACK, 1);
            container->updateItems();
            isResearching = true;

            // 10 seconds per unit of research for automation.
            // This depends on the technology type.
            // TODO: Make this configurable.
            researchUnitTicksRemaining = 10 * FRAMES_PER_SECOND;
        }
    }

    if (researchUnitTicksRemaining <= 0) {
        // TODO: Add research completion logic.

        // 10 seconds per unit of research for automation.
        // This depends on the technology type.
        // TODO: Make this configurable.
        researchUnitTicksRemaining = 10 * FRAMES_PER_SECOND;

        isResearching = false;
    }
}
