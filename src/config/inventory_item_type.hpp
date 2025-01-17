#pragma once

enum class InventoryItemType {
    NONE = 0,  // Invalid / null item or stack
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
    REPAIR_PACK,
    BOILER,
    STEAM_ENGINE,
    BURNER_MINING_DRILL,
    ELECTRIC_MINING_DRILL,
    OFFSHORE_PUMP,
    STONE_FURNACE,
    LAB,
    // Intermediate products (raw)
    WOOD,
    COAL,
    STONE,
    IRON_ORE,
    COPPER_ORE,
    FISH,
    // Intermediate products (other)
    IRON_PLATE,
    COPPER_PLATE,
    COPPER_CABLE,
    IRON_STICK,
    IRON_GEAR_WHEEL,
    ELECTRONIC_CIRCUIT,
    AUTOMATION_SCIENCE_PACK,
    // Combat
    PISTOL,
    FIREARM_MAGAZINE,
    LIGHT_ARMOR,
    RADAR
};
