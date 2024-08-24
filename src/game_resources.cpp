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
    case static_cast<int>(InventoryItemType::IRON_GEAR_WHEEL):
        return "data/base/graphics/icons/iron-gear-wheel.png";
    case static_cast<int>(InventoryItemType::ELECTRIC_MINING_DRILL):
        return "data/base/graphics/icons/electric-mining-drill.png";
    case static_cast<int>(InventoryItemType::BURNER_MINING_DRILL):
        return "data/base/graphics/icons/burner-mining-drill.png";
    case static_cast<int>(InventoryItemType::BOILER):
        return "data/base/graphics/icons/boiler.png";
    case static_cast<int>(InventoryItemType::STONE_FURNACE):
        return "data/base/graphics/icons/stone-furnace.png";
    case static_cast<int>(InventoryItemType::IRON_ORE):
        return "data/base/graphics/icons/iron-ore.png";
    case static_cast<int>(InventoryItemType::COAL):
        return "data/base/graphics/icons/coal.png";
    case static_cast<int>(InventoryItemType::COPPER_ORE):
        return "data/base/graphics/icons/copper-ore.png";
    case static_cast<int>(InventoryItemType::STONE):
        return "data/base/graphics/icons/stone.png";
    case static_cast<int>(InventoryItemType::WOOD):
        return "data/base/graphics/icons/wood.png";
    case static_cast<int>(InventoryItemType::IRON_PLATE):
        return "data/base/graphics/icons/iron-plate.png";
    // case static_cast<int>(InventoryItemType::STEEL):
    //     return "data/base/graphics/icons/steel-plate.png";
    case static_cast<int>(InventoryItemType::COPPER_PLATE):
        return "data/base/graphics/icons/copper-plate.png";
    case static_cast<int>(InventoryItemType::STONE_BRICK):
        return "data/base/graphics/icons/stone-brick.png";
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
    case static_cast<int>(InventoryItemType::IRON_ORE):
        return "iron-ore";
    case static_cast<int>(InventoryItemType::COAL):
        return "coal";
    case static_cast<int>(InventoryItemType::COPPER_ORE):
        return "copper-ore";
    case static_cast<int>(InventoryItemType::STONE):
        return "stone";
    case static_cast<int>(InventoryItemType::WOOD):
        return "wood";
    case static_cast<int>(InventoryItemType::IRON_PLATE):
        return "iron-plate";
    // case static_cast<int>(InventoryItemType::STEEL):
    //     return "steel";
    case static_cast<int>(InventoryItemType::COPPER_PLATE):
        return "copper-plate";
    case static_cast<int>(InventoryItemType::STONE_BRICK):
        return "stone-brick";
    case static_cast<int>(InventoryItemType::STONE_FURNACE):
        return "stone-furnace";
    case static_cast<int>(InventoryItemType::IRON_GEAR_WHEEL):
        return "iron-gear-wheel";
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
    loadInventorySprite(InventoryItemType::IRON_ORE);
    loadInventorySprite(InventoryItemType::COAL);
    loadInventorySprite(InventoryItemType::COPPER_ORE);
    loadInventorySprite(InventoryItemType::STONE);
    loadInventorySprite(InventoryItemType::WOOD);
    loadInventorySprite(InventoryItemType::IRON_PLATE);
    // loadInventorySprite(InventoryItemType::STEEL);
    loadInventorySprite(InventoryItemType::COPPER_PLATE);
    loadInventorySprite(InventoryItemType::STONE_BRICK);
    loadInventorySprite(InventoryItemType::STONE_FURNACE);
    loadInventorySprite(InventoryItemType::WOODEN_CHEST, /* isMasked= */ false);
    loadInventorySprite(InventoryItemType::IRON_CHEST);
    loadInventorySprite(InventoryItemType::TRANSPORT_BELT);
    loadInventorySprite(InventoryItemType::IRON_GEAR_WHEEL);
    loadInventorySprite(InventoryItemType::ELECTRIC_MINING_DRILL);
    loadInventorySprite(InventoryItemType::BURNER_MINING_DRILL);
    loadInventorySprite(InventoryItemType::BOILER);
    loadInventorySprite(InventoryItemType::IRON_GEAR_WHEEL);

}

GameResources* instance = nullptr;

GameResources& GameResources::getInstance() {
    if (instance == nullptr) {
        instance = new GameResources();
        instance->init();
    }
    return *instance;
}
