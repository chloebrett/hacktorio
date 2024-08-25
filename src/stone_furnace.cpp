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
#include "config/recipe_configuration.hpp"

StoneFurnace::StoneFurnace(Gui &gui, RecipeConfiguration &recipeConfiguration, sf::Vector2f pos) :
gui(gui), recipeConfiguration(recipeConfiguration), Entity(
    /* position= */ pos,
    /* size= */ sf::Vector2f(2 * GRID_SIZE, 2 * GRID_SIZE),
    /* onClick= */ [this](Cursor &cursor) {
        std::cout << "Stone furnace clicked" << std::endl;
        this->gui.showPanelForEntity(this->container);
    },
    /* onRender= */ [this](
        SceneNode &node,
        sf::RenderWindow &window,
        sf::Vector2f absolutePos
    ) {
        sf::Sprite sprite = *GameResources::getInstance().getEntitySprite(EntityType::STONE_FURNACE);
        sprite.setPosition(absolutePos);
        window.draw(sprite);

        // TODO: separate out an onUpdate callback for scene nodes / entities.
        this->onTick();
    }
) {
    container = new Container();
}

void StoneFurnace::onTick() {
    if (currentRecipe == nullptr) {
        if (container->getItemCount(InventoryItemType::IRON_ORE) > 0) {
            currentRecipe = recipeConfiguration.getRecipeByOutputType(InventoryItemType::IRON_PLATE);
            isSmelting = true;
            // TODO
        }
    }
}
