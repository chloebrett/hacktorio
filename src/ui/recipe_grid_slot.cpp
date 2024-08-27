#include "recipe_grid_slot.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../config/constants.hpp"
#include "../config/game_resources.hpp"
#include "../config/recipe_configuration.hpp"
#include "../cursor.hpp"
#include "../recipe.hpp"
#include "../scene_node.hpp"
#include "gui.hpp"
#include "recipe_position.hpp"

RecipeGridSlot::RecipeGridSlot(Gui &gui, RecipePanel &recipePanel,
                               RecipeConfiguration &recipeConfiguration, RecipePosition &position)
    : gui(gui),
      recipePanel(recipePanel),
      recipeConfiguration(recipeConfiguration),
      position(position),
      SceneNode(
          /* position= */
          sf::Vector2f(position.getColumn() * GRID_SIZE,
                       RECIPE_TAB_LIST_HEIGHT + position.getRow() * GRID_SIZE),
          /* size= */ sf::Vector2f(GRID_SIZE, GRID_SIZE),
          /* onClick= */
          [this, &recipeConfiguration, &position, &gui](Cursor &cursor) {
              if (!isVisible()) return;

              std::cout << "RecipeGridSlot clicked" << std::endl;
              Recipe *recipe = recipeConfiguration.getRecipeAtPosition(position);

              if (recipe != nullptr) {
                  std::cout << "Recipe found" << std::endl;
                  gui.startCraftingRecipe(recipe);
              } else {
                  std::cout << "No recipe found" << std::endl;
              }
          },
          /* onRender= */
          [this, &recipeConfiguration, &position](SceneNode &node, sf::RenderWindow &window,
                                                  sf::Vector2f absolutePos) {
              // TODO: figure out why the normal visibility check isn't working
              if (!isVisible()) return;

              sf::RectangleShape itemRect;
              itemRect.setPosition(absolutePos);
              itemRect.setSize(size);
              itemRect.setFillColor(sf::Color(0, 0, 0, 0));
              itemRect.setOutlineColor(sf::Color(40, 40, 40, 255));
              itemRect.setOutlineThickness(1.0);
              window.draw(itemRect);

              Recipe *recipe = recipeConfiguration.getRecipeAtPosition(position);
              if (recipe == nullptr) {
                  return;
              }
              ItemStack *itemStack = recipe->getOutputs().front();  // first element of vector

              sf::Sprite sprite = *GameResources::getInstance().getInventorySprite(itemStack->type);
              sprite.setPosition(absolutePos);
              window.draw(sprite);
          }) {}

bool RecipeGridSlot::isVisible() {
    return recipePanel.getSelectedTabIndex() == position.getTabIndex();
}
