#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "inventory_item_type.hpp"

using namespace std;

class GameResources {
    public:
    GameResources();
    void init();
    void loadSprite(string key, string filename);
    void loadInventorySprite(InventoryItemType inventoryItemType);
    string inventoryItemTypeToKey(InventoryItemType inventoryItemType);
    static GameResources& getInstance();
    sf::Texture* getTexture(string key) { return textures[key]; }
    sf::Font* getFont(string key) { return fonts[key]; }
    sf::Sprite* getSprite(string key) { return sprites[key]; }
    sf::Sprite* getInventorySprite(InventoryItemType inventoryItemType) { return sprites[inventoryItemTypeToKey(inventoryItemType)]; }
    sf::Color* getColor(string key) { return colors[key]; }

    private:
    string inventoryItemTypeToFilename(InventoryItemType inventoryItemType);
    map<string, sf::Texture*> textures;
    map<string, sf::Font*> fonts;
    map<string, sf::Sprite*> sprites;
    map<string, sf::Color*> colors;
};
