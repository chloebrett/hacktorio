#include "renderer.hpp"
#include "config/constants.hpp"
#include "SFML/Graphics.hpp"
#include "player.hpp"
#include "resource_patch.hpp"
#include "game.hpp"
#include "resource_patch.hpp"
#include "config/inventory_item_type.hpp"
#include "config/resource_patch_type.hpp"
#include <iostream>
#include <memory>
#include "wooden_chest.hpp"
#include "item_stack.hpp"
#include <vector>

Renderer::Renderer(sf::RenderWindow &window) : window(window) {}

void Renderer::render(SceneNode &rootSceneNode)
{
    window.clear();
    rootSceneNode.render(window, sf::Vector2f(0, 0));
    window.display();
}
