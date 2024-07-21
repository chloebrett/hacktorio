#include "engine.hpp"
#include "media.hpp"

#include <iostream>

void Engine::init() {
    Media media;
    media.init();

    std::cout << "Engine initialized" << std::endl;
};
