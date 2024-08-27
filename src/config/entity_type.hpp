#pragma once

/** Entities that can be placed on the map. */
enum class EntityType {
    // Logistics
    WOODEN_CHEST,
    IRON_CHEST,
    TRANSPORT_BELT,
    BURNER_INSERTER,
    INSERTER,
    SMALL_ELECTRIC_POLE,
    PIPE,
    PIPE_TO_GROUND,
    STONE_BRICK,
    // Production
    BOILER,
    STEAM_ENGINE,
    BURNER_MINING_DRILL,
    ELECTRIC_MINING_DRILL,
    OFFSHORE_PUMP,
    STONE_FURNACE,
    LAB,
    // Combat
    RADAR
};
