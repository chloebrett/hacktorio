#include "stone_furnace.hpp"

#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>
#include <vector>

#include "../config/constants.hpp"
#include "../config/entity_type.hpp"
#include "../config/game_resources.hpp"
#include "../config/recipe_configuration.hpp"
#include "../container.hpp"
#include "../cursor.hpp"
#include "../entity.hpp"
#include "../ui/gui.hpp"

StoneFurnace::StoneFurnace(Gui &gui, RecipeConfiguration &recipeConfiguration, sf::Vector2f pos)
    : gui(gui),
      recipeConfiguration(recipeConfiguration),
      Entity(
          /* position= */
          pos,
          /* size= */ sf::Vector2f(2 * GRID_SIZE, 2 * GRID_SIZE),
          /* onClick= */
          [this](Cursor &cursor) {
              std::cout << "Stone furnace clicked" << std::endl;
              this->gui.showPanelForEntity(this->container);
          },
          /* onRender= */
          [this](SceneNode &node, sf::RenderWindow &window, sf::Vector2f absolutePos) {
              sf::Sprite sprite =
                  *GameResources::getInstance().getEntitySprite(EntityType::STONE_FURNACE);
              sprite.setPosition(absolutePos);
              window.draw(sprite);
          }) {
    container = new Container();
}

void StoneFurnace::onTick() {
    if (currentRecipe == nullptr) {
        if (container->getItemCount(InventoryItemType::IRON_ORE) > 0) {
            currentRecipe =
                recipeConfiguration.getRecipeByOutputType(InventoryItemType::IRON_PLATE);
        } else if (container->getItemCount(InventoryItemType::COPPER_ORE) > 0) {
            currentRecipe =
                recipeConfiguration.getRecipeByOutputType(InventoryItemType::COPPER_PLATE);
        } else if (container->getItemCount(InventoryItemType::STONE) > 0) {
            currentRecipe =
                recipeConfiguration.getRecipeByOutputType(InventoryItemType::STONE_BRICK);
        } else {
            return;
        }
    }
    cout << "Smelting: " << isSmelting << " " << currentRecipe->getName() << endl;
    cout << "Ticks remaining: " << smeltUnitTicksRemaining << " " << fuelUnitTicksRemaining << endl;

    if (isSmelting) {
        smeltUnitTicksRemaining--;
        fuelUnitTicksRemaining--;
    } else {
        // Assume only one input and output for smelting recipes.
        ItemStack *input = currentRecipe->getInputs().front();

        if (container->getItemCount(input->getType()) >= input->getAmount() &&
            fuelUnitTicksRemaining > 0) {
            container->removeItem(input->getType(), input->getAmount());
            container->updateItems();
            isSmelting = true;
            smeltUnitTicksRemaining = currentRecipe->getTime() * FRAMES_PER_SECOND;
        }
    }

    if (smeltUnitTicksRemaining <= 0) {
        ItemStack *output = currentRecipe->getOutputs().front();
        container->addItem(output->getType(), output->getAmount());
        container->updateItems();
        smeltUnitTicksRemaining = currentRecipe->getTime() * FRAMES_PER_SECOND;

        isSmelting = false;
        currentRecipe = nullptr;
    }

    if (fuelUnitTicksRemaining <= 0) {
        if (container->getItemCount(InventoryItemType::COAL) > 0) {
            container->removeItem(InventoryItemType::COAL, 1);
            container->updateItems();

            // According to the wiki, coal consumption is 0.0225/second.
            // https://wiki.factorio.com/Stone_furnace
            // 1 / 0.0225 = 44.4444 = 400 / 9
            fuelUnitTicksRemaining = 400.0 / 9.0 * FRAMES_PER_SECOND;
        } else {
            isSmelting = false;
        }
    }
}
