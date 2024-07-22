#include "game.hpp"
#include "player.hpp"
#include "iron_patch.hpp"

#include "SFML/Graphics.hpp"
#include <iostream>

void Game::start()
{
    std::cout << "Starting game" << std::endl;

    float GRID_SIZE = 32.0f;
    float FRAMES_PER_SECOND = 60.0f;
    int SCREEN_WIDTH = 1920;
    int SCREEN_HEIGHT = 1080;
    sf::Vector2f SCREEN_SIZE = sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT);

    sf::Color blue = sf::Color(81.0f, 168.0f, 194.0f, 255.0f);
    sf::Color green = sf::Color(85.0f, 107.0f, 95.0f, 255.0f);
    sf::Color grey = sf::Color(80.0f, 81.0f, 84.0f, 255.0f);

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Hacktorio");

    sf::RectangleShape background;
    background.setSize(SCREEN_SIZE);
    background.setPosition(0.0f, 0.0f);
    background.setFillColor(green);

    Player player;

    sf::RectangleShape playerRect;
    playerRect.setSize(sf::Vector2f(1 * GRID_SIZE, 1 * GRID_SIZE));
    playerRect.setPosition(2 * GRID_SIZE, 2 * GRID_SIZE);
    playerRect.setFillColor(blue);

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time timePerFrame = sf::seconds(1.0f / FRAMES_PER_SECOND);

    // Place iron patches
    std::vector<IronPatch> ironPatches;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            IronPatch ironPatch;
            ironPatch.setPosition(sf::Vector2f((10 + i) * GRID_SIZE, (10 + j) * GRID_SIZE));
            ironPatches.push_back(ironPatch);
        }
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > timePerFrame)
        {
            timeSinceLastUpdate -= timePerFrame;
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

            playerRect.setPosition(player.getPosition());
        }

        window.clear();
        window.draw(background);
        for (IronPatch ironPatch : ironPatches)
        {
            if (ironPatch.getRemaining() > 0)
            {
                sf::RectangleShape ironPatchRect;
                ironPatchRect.setSize(sf::Vector2f(1 * GRID_SIZE, 1 * GRID_SIZE));
                ironPatchRect.setPosition(ironPatch.getPosition());
                ironPatchRect.setFillColor(grey);
                window.draw(ironPatchRect);
            }
        }
        window.draw(playerRect);
        window.display();
    }
};
