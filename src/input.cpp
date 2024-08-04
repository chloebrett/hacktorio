#include "input.hpp"
#include "player.hpp"
#include "SFML/Graphics.hpp"
#include "chest.hpp"
#include "constants.hpp"
#include "resource_patch.hpp"

using namespace std;

Input::Input(
    sf::RenderWindow &window,
    Player &player,
    Chest &chest,
    vector<ResourcePatch*> &resourcePatches
) : window(window), player(player), chest(chest), resourcePatches(resourcePatches),
isInventoryOpen(false),
selectedInventoryItemIndex(0),
selectedOtherItemIndex(0) {};

void Input::handleQueuedEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::I)
            {
                isInventoryOpen = !isInventoryOpen;
            }
            
            if (event.key.code == sf::Keyboard::Down)
            {
                selectedInventoryItemIndex++;
            }
            if (event.key.code == sf::Keyboard::Up)
            {
                selectedInventoryItemIndex--;
            }
            if (event.key.code == sf::Keyboard::U)
            {
                selectedOtherItemIndex--;
            }
            if (event.key.code == sf::Keyboard::J)
            {
                selectedOtherItemIndex++;
            }
            if (event.key.code == sf::Keyboard::Right)
            {
                InventoryItemType itemType;
                int i = 0;
                for (auto& item : player.getContents()) {
                    if ((selectedInventoryItemIndex % player.getContents().size()) == i) {
                        itemType = item.first;
                        break;
                    }
                    i++;
                }

                int count = player.getItemCount(itemType);
                if (count > 0 && chest.getFreeSpace() > 0)
                {
                    std::cout << "Moving item from player to chest" << std::endl;
                    std::cout << chest.getFreeSpace() << std::endl;
                    player.removeItem(itemType, 1);
                    chest.addItem(itemType, 1);
                }
            }
            if (event.key.code == sf::Keyboard::Left)
            {
                InventoryItemType itemType;
                int i = 0;
                for (auto& item : chest.getContents()) {
                    if ((selectedOtherItemIndex % chest.getContents().size()) == i) {
                        itemType = item.first;
                        break;
                    }
                    i++;
                }

                int count = chest.getItemCount(itemType);
                if (count > 0)
                {
                    chest.removeItem(itemType, 1);
                    player.addItem(itemType, 1);
                }
            }
        }
    }
}

bool Input::getIsInventoryOpen() {
    return isInventoryOpen;
}

int Input::getSelectedInventoryItemIndex() {
    return selectedInventoryItemIndex;
}

int Input::getSelectedOtherItemIndex() {
    return selectedOtherItemIndex;
}

void Input::handleOngoingEvents() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        sf::Vector2f playerPosition = player.getPosition();
        std::cout << "playerPosition: " << playerPosition.x << ", " << playerPosition.y << std::endl;
        std::cout << "rps" << resourcePatches.size() << std::endl;
        for (const auto &resourcePatch : resourcePatches)
        {
            sf::Vector2f resourcePatchPosition = resourcePatch->getPosition();
            sf::Vector2f diff = playerPosition - resourcePatchPosition;
            if (abs(diff.x) < 0.5 * GRID_SIZE && abs(diff.y) < 0.5 * GRID_SIZE)
            {
                if (resourcePatch->getRemaining() > 0)
                {
                    bool didMine = resourcePatch->mine(player.getMiningSpeed() / FRAMES_PER_SECOND);
                    std::cout << "Mined: " << didMine << std::endl;
                    if (didMine)
                    {
                        player.addItem(resourcePatch->getInventoryItemType(), 1);
                    }
                }
            }
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        player.setPosition(sf::Vector2f(player.getPosition().x, player.getPosition().y - player.getMoveSpeed()));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        player.setPosition(sf::Vector2f(player.getPosition().x, player.getPosition().y + player.getMoveSpeed()));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        player.setPosition(sf::Vector2f(player.getPosition().x - player.getMoveSpeed(), player.getPosition().y));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        player.setPosition(sf::Vector2f(player.getPosition().x + player.getMoveSpeed(), player.getPosition().y));
    }
}
