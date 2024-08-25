#pragma once

#include "container.hpp"
#include "item_stack.hpp"
#include <SFML/Graphics.hpp>
#include "entity_manager.hpp"

class Cursor {
    public:
    Cursor(EntityManager &entityManager);
    ItemStack* getItemStack();
    void setItemStack(ItemStack *itemStack);
    void handleLeftClickOnEmptySpace(sf::Vector2i mousePosition);

    private:
    ItemStack* itemStack;
    EntityManager &entityManager;
};
