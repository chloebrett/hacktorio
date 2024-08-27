#pragma once

#include <SFML/Graphics.hpp>
#include <map>

#include "entity_type.hpp"
#include "inventory_item_type.hpp"

class GameResources {
   public:
    GameResources();
    void init();
    void loadSprite(std::string key, std::string filename);
    void loadInventorySprite(InventoryItemType inventoryItemType, bool isMasked = true);
    void loadEntitySprite(EntityType entityType);
    std::string inventoryItemTypeToKey(InventoryItemType inventoryItemType);
    std::string entityTypeToKey(EntityType entityType);
    static GameResources& getInstance();
    sf::Texture* getTexture(std::string key) { return textures[key]; }
    sf::Font* getFont(std::string key) { return fonts[key]; }
    sf::Sprite* getSprite(std::string key) { return sprites[key]; }
    sf::Sprite* getInventorySprite(InventoryItemType inventoryItemType) {
        return sprites[inventoryItemTypeToKey(inventoryItemType)];
    }
    sf::Sprite* getEntitySprite(EntityType entityType) {
        return sprites[entityTypeToKey(entityType)];
    }
    sf::Color* getColor(std::string key) { return colors[key]; }

   private:
    std::string inventoryItemTypeToFilename(InventoryItemType inventoryItemType);
    std::string entityTypeToFilename(EntityType entityType);
    std::map<std::string, sf::Texture*> textures;
    std::map<std::string, sf::Font*> fonts;
    std::map<std::string, sf::Sprite*> sprites;
    std::map<std::string, sf::Color*> colors;
};
