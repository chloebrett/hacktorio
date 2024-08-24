#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "entity_type.hpp"
#include "inventory_item_type.hpp"

using namespace std;

class GameResources {
    public:
    GameResources();
    void init();
    void loadSprite(string key, string filename);
    void loadInventorySprite(InventoryItemType inventoryItemType, bool isMasked = true);
    void loadEntitySprite(EntityType entityType);
    string inventoryItemTypeToKey(InventoryItemType inventoryItemType);
    string entityTypeToKey(EntityType entityType);
    static GameResources& getInstance();
    sf::Texture* getTexture(string key) { return textures[key]; }
    sf::Font* getFont(string key) { return fonts[key]; }
    sf::Sprite* getSprite(string key) { return sprites[key]; }
    sf::Sprite* getInventorySprite(InventoryItemType inventoryItemType) { return sprites[inventoryItemTypeToKey(inventoryItemType)]; }
    sf::Sprite* getEntitySprite(EntityType entityType) { return sprites[entityTypeToFilename(entityType)]; }
    sf::Color* getColor(string key) { return colors[key]; }

    private:
    string inventoryItemTypeToFilename(InventoryItemType inventoryItemType);
    string entityTypeToFilename(EntityType entityType);
    map<string, sf::Texture*> textures;
    map<string, sf::Font*> fonts;
    map<string, sf::Sprite*> sprites;
    map<string, sf::Color*> colors;
};
