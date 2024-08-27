#pragma once

#include <SFML/Graphics.hpp>

#include "../container.hpp"
#include "../entity.hpp"

class ElectricMiningDrill : public Entity {
   public:
    ElectricMiningDrill(sf::Vector2f pos);
};
