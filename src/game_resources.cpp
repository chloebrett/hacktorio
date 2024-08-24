#pragma once

#include "inventory_item_type.hpp"
#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>
#include "game_resources.hpp"

using namespace std;

GameResources::GameResources() {}

string GameResources::inventoryItemTypeToFilename(InventoryItemType inventoryItemType)
{
    switch (static_cast<int>(inventoryItemType))
    {
    case static_cast<int>(InventoryItemType::WOODEN_CHEST):
        return "data/base/graphics/entity/wooden-chest/wooden-chest.png";
    case static_cast<int>(InventoryItemType::IRON_CHEST):
        return "data/base/graphics/icons/iron-chest.png";
    case static_cast<int>(InventoryItemType::TRANSPORT_BELT):
        return "data/base/graphics/icons/transport-belt.png";
    case static_cast<int>(InventoryItemType::BURNER_INSERTER):
        return "data/base/graphics/icons/burner-inserter.png";
    case static_cast<int>(InventoryItemType::INSERTER):
        return "data/base/graphics/icons/inserter.png";
    case static_cast<int>(InventoryItemType::SMALL_ELECTRIC_POLE):
        return "data/base/graphics/icons/small-electric-pole.png";
    case static_cast<int>(InventoryItemType::PIPE):
        return "data/base/graphics/icons/pipe.png";
    case static_cast<int>(InventoryItemType::PIPE_TO_GROUND):
        return "data/base/graphics/icons/pipe-to-ground.png";
    case static_cast<int>(InventoryItemType::STONE_BRICK):
        return "data/base/graphics/icons/stone-brick.png";
    case static_cast<int>(InventoryItemType::REPAIR_PACK):
        return "data/base/graphics/icons/repair-pack.png";
    case static_cast<int>(InventoryItemType::BOILER):        
        return "data/base/graphics/icons/boiler.png";
    case static_cast<int>(InventoryItemType::STEAM_ENGINE):
        return "data/base/graphics/icons/steam-engine.png";
    case static_cast<int>(InventoryItemType::BURNER_MINING_DRILL):
        return "data/base/graphics/icons/burner-mining-drill.png";
    case static_cast<int>(InventoryItemType::ELECTRIC_MINING_DRILL):
        return "data/base/graphics/icons/electric-mining-drill.png";
    case static_cast<int>(InventoryItemType::OFFSHORE_PUMP):
        return "data/base/graphics/icons/offshore-pump.png";
    case static_cast<int>(InventoryItemType::STONE_FURNACE):
        return "data/base/graphics/icons/stone-furnace.png";
    case static_cast<int>(InventoryItemType::LAB):
        return "data/base/graphics/icons/lab.png";
    case static_cast<int>(InventoryItemType::WOOD):
        return "data/base/graphics/icons/wood.png";
    case static_cast<int>(InventoryItemType::COAL):
        return "data/base/graphics/icons/coal.png";
    case static_cast<int>(InventoryItemType::STONE):
        return "data/base/graphics/icons/stone.png";
    case static_cast<int>(InventoryItemType::IRON_ORE):
        return "data/base/graphics/icons/iron-ore.png";
    case static_cast<int>(InventoryItemType::COPPER_ORE):
        return "data/base/graphics/icons/copper-ore.png";
    case static_cast<int>(InventoryItemType::FISH):
        return "data/base/graphics/icons/fish.png";
    case static_cast<int>(InventoryItemType::IRON_PLATE):
        return "data/base/graphics/icons/iron-plate.png";
    case static_cast<int>(InventoryItemType::COPPER_PLATE):
        return "data/base/graphics/icons/copper-plate.png";
    case static_cast<int>(InventoryItemType::COPPER_CABLE):
        return "data/base/graphics/icons/copper-cable.png";
    case static_cast<int>(InventoryItemType::IRON_STICK):
        return "data/base/graphics/icons/iron-stick.png";
    case static_cast<int>(InventoryItemType::IRON_GEAR_WHEEL):
        return "data/base/graphics/icons/iron-gear-wheel.png";
    case static_cast<int>(InventoryItemType::ELECTRONIC_CIRCUIT):
        return "data/base/graphics/icons/electronic-circuit.png";
    case static_cast<int>(InventoryItemType::AUTOMATION_SCIENCE_PACK):
        return "data/base/graphics/icons/automation-science-pack.png";
    case static_cast<int>(InventoryItemType::PISTOL):
        return "data/base/graphics/icons/pistol.png";
    case static_cast<int>(InventoryItemType::FIREARM_MAGAZINE):
        return "data/base/graphics/icons/firearm-magazine.png";
    case static_cast<int>(InventoryItemType::LIGHT_ARMOR):
        return "data/base/graphics/icons/light-armor.png";
    case static_cast<int>(InventoryItemType::RADAR):
        return "data/base/graphics/icons/radar.png";
    default:
        return "data/core/graphics/cancel.png";
    }
}

std::string GameResources::inventoryItemTypeToKey(InventoryItemType inventoryItemType)
{
    switch (static_cast<int>(inventoryItemType))
    {
    case static_cast<int>(InventoryItemType::WOODEN_CHEST):
        return "wooden-chest";
    case static_cast<int>(InventoryItemType::IRON_CHEST):
        return "iron-chest";
    case static_cast<int>(InventoryItemType::TRANSPORT_BELT):
        return "transport-belt";
    case static_cast<int>(InventoryItemType::BURNER_INSERTER):
        return "burner-inserter";
    case static_cast<int>(InventoryItemType::INSERTER):
        return "inserter";
    case static_cast<int>(InventoryItemType::SMALL_ELECTRIC_POLE):
        return "small-electric-pole";
    case static_cast<int>(InventoryItemType::PIPE):
        return "pipe";
    case static_cast<int>(InventoryItemType::PIPE_TO_GROUND):
        return "pipe-to-ground";
    case static_cast<int>(InventoryItemType::STONE_BRICK):
        return "stone-brick";
    case static_cast<int>(InventoryItemType::REPAIR_PACK):
        return "repair-pack";
    case static_cast<int>(InventoryItemType::BOILER):        
        return "boiler";
    case static_cast<int>(InventoryItemType::STEAM_ENGINE):
        return "steam-engine";
    case static_cast<int>(InventoryItemType::BURNER_MINING_DRILL):
        return "burner-mining-drill";
    case static_cast<int>(InventoryItemType::ELECTRIC_MINING_DRILL):
        return "electric-mining-drill";
    case static_cast<int>(InventoryItemType::OFFSHORE_PUMP):
        return "offshore-pump";
    case static_cast<int>(InventoryItemType::STONE_FURNACE):
        return "stone-furnace";
    case static_cast<int>(InventoryItemType::LAB):
        return "lab";
    case static_cast<int>(InventoryItemType::WOOD):
        return "wood";
    case static_cast<int>(InventoryItemType::COAL):
        return "coal";
    case static_cast<int>(InventoryItemType::STONE):
        return "stone";
    case static_cast<int>(InventoryItemType::IRON_ORE):
        return "iron-ore";
    case static_cast<int>(InventoryItemType::COPPER_ORE):
        return "copper-ore";
    case static_cast<int>(InventoryItemType::FISH):
        return "fish";
    case static_cast<int>(InventoryItemType::IRON_PLATE):
        return "iron-plate";
    case static_cast<int>(InventoryItemType::COPPER_PLATE):
        return "copper-plate";
    case static_cast<int>(InventoryItemType::COPPER_CABLE):
        return "copper-cable";
    case static_cast<int>(InventoryItemType::IRON_STICK):
        return "iron-stick";
    case static_cast<int>(InventoryItemType::IRON_GEAR_WHEEL):
        return "iron-gear-wheel";
    case static_cast<int>(InventoryItemType::ELECTRONIC_CIRCUIT):
        return "electronic-circuit";
    case static_cast<int>(InventoryItemType::AUTOMATION_SCIENCE_PACK):
        return "automation-science-pack";
    case static_cast<int>(InventoryItemType::PISTOL):
        return "pistol";
    case static_cast<int>(InventoryItemType::FIREARM_MAGAZINE):
        return "firearm-magazine";
    case static_cast<int>(InventoryItemType::LIGHT_ARMOR):
        return "light-armor";
    case static_cast<int>(InventoryItemType::RADAR):
        return "radar";
    default:
        return "unknown";
    }
}


void GameResources::loadSprite(string key, string filename) {
    textures[key] = new sf::Texture();
    if (!textures[key]->loadFromFile(filename))
    {
        cout << "Failed to load texture" << endl;
    }
    sprites[key] = new sf::Sprite(*textures[key]);
}

void GameResources::loadInventorySprite(InventoryItemType inventoryItemType, bool isMasked) {
    string key = inventoryItemTypeToKey(inventoryItemType);
    textures[key] = new sf::Texture();
    if (!textures[key]->loadFromFile(inventoryItemTypeToFilename(inventoryItemType)))
    {
        // Handle loading error
        cout << "Failed to load texture" << endl;
    }
    sprites[key] = new sf::Sprite(*textures[key]);
    if (isMasked) {
        sprites[key]->setTextureRect(sf::IntRect(64, 0, 32, 32));
    }
}

void GameResources::init() {
    fonts["main"] = new sf::Font();
    if (!fonts["main"]->loadFromFile("res/Inconsolata-Regular.ttf"))
    {
        cout << "Failed to load font" << endl;
    }

    loadSprite("chest", "data/base/graphics/entity/wooden-chest/wooden-chest.png");
    loadInventorySprite(InventoryItemType::WOODEN_CHEST, /* isMasked= */ false);
    loadInventorySprite(InventoryItemType::IRON_CHEST);
    loadInventorySprite(InventoryItemType::TRANSPORT_BELT);
    loadInventorySprite(InventoryItemType::BURNER_INSERTER);
    loadInventorySprite(InventoryItemType::INSERTER);
    loadInventorySprite(InventoryItemType::SMALL_ELECTRIC_POLE);
    loadInventorySprite(InventoryItemType::PIPE);
    loadInventorySprite(InventoryItemType::PIPE_TO_GROUND);
    loadInventorySprite(InventoryItemType::STONE_BRICK);
    loadInventorySprite(InventoryItemType::REPAIR_PACK);
    loadInventorySprite(InventoryItemType::BOILER);
    loadInventorySprite(InventoryItemType::STEAM_ENGINE);
    loadInventorySprite(InventoryItemType::BURNER_MINING_DRILL);
    loadInventorySprite(InventoryItemType::ELECTRIC_MINING_DRILL);
    loadInventorySprite(InventoryItemType::OFFSHORE_PUMP);
    loadInventorySprite(InventoryItemType::STONE_FURNACE);
    loadInventorySprite(InventoryItemType::LAB);
    loadInventorySprite(InventoryItemType::WOOD);
    loadInventorySprite(InventoryItemType::COAL);
    loadInventorySprite(InventoryItemType::STONE);
    loadInventorySprite(InventoryItemType::IRON_ORE);
    loadInventorySprite(InventoryItemType::COPPER_ORE);
    loadInventorySprite(InventoryItemType::FISH);
    loadInventorySprite(InventoryItemType::IRON_PLATE);
    loadInventorySprite(InventoryItemType::COPPER_PLATE);
    loadInventorySprite(InventoryItemType::COPPER_CABLE);
    loadInventorySprite(InventoryItemType::IRON_STICK);
    loadInventorySprite(InventoryItemType::IRON_GEAR_WHEEL);
    loadInventorySprite(InventoryItemType::ELECTRONIC_CIRCUIT);
    loadInventorySprite(InventoryItemType::AUTOMATION_SCIENCE_PACK);
    loadInventorySprite(InventoryItemType::PISTOL);
    loadInventorySprite(InventoryItemType::FIREARM_MAGAZINE);
    loadInventorySprite(InventoryItemType::LIGHT_ARMOR);
    loadInventorySprite(InventoryItemType::RADAR);
}

GameResources* instance = nullptr;

GameResources& GameResources::getInstance() {
    if (instance == nullptr) {
        instance = new GameResources();
        instance->init();
    }
    return *instance;
}
