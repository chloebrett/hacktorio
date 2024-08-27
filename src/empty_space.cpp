#include "empty_space.hpp"

#include <SFML/Graphics.hpp>

#include "config/constants.hpp"
#include "entity_placement_manager.hpp"
#include "scene_node.hpp"

EmptySpace::EmptySpace(sf::Vector2f pos, EntityPlacementManager &entityPlacementManager)
    : entityPlacementManager(entityPlacementManager),
      SceneNode(
          /* position= */
          pos,
          /* size= */ sf::Vector2f(GRID_SIZE, GRID_SIZE),
          /* onClick= */
          [this, pos, &entityPlacementManager](Cursor &cursor) {
              ItemStack *itemStack = cursor.getItemStack();
              if (itemStack != nullptr) {
                  bool success = entityPlacementManager.tryPlaceEntity(itemStack->getType(), pos,
                                                                       cursor.getRotation());
                  if (success) {
                      // TODO: memory leak
                      if (itemStack->getAmount() == 1) {
                          cursor.setItemStack(nullptr);
                      } else {
                          cursor.setItemStack(
                              new ItemStack(itemStack->getType(), itemStack->getAmount() - 1));
                      }
                  }
              }
          },
          /* onRender= */
          [this](SceneNode &node, sf::RenderWindow &window, sf::Vector2f absolutePos) {
              // invisible, but clickable (so just render nothing, but 'isVisible' is true)
              // TODO: separate these concepts.
          }) {}

bool EmptySpace::canPlaceItem() { return true; }
