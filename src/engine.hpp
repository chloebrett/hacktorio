#pragma once

/**
 * Interface for the game engine. This abstracts away operations that aren't specific to game business logic -
 * for example, handling game ticks, managing the objects in the game world, and placing things on the map.
 * 
 * Talks to "media.hpp" to actualize the game state.
 */
class Engine {
    public:
    void init();
};
