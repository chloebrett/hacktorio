#include "button.hpp"

#include <SFML/Graphics.hpp>
#include <functional>

#include "../config/constants.hpp"
#include "../config/game_resources.hpp"
#include "../cursor.hpp"
#include "../scene_node.hpp"
#include "gui.hpp"

Button::Button(sf::Vector2f position, sf::Vector2f size, sf::Color fillColor,
               std::string textString, std::function<void(Cursor &)> onClick)
    : SceneNode(
          /* position= */ position,
          /* size= */ size,
          /* onClick= */ onClick,
          /* onRender= */
          [this, fillColor, textString](SceneNode &node, sf::RenderWindow &window,
                                        sf::Vector2f absolutePos) {
              sf::RectangleShape mainRect;
              mainRect.setSize(this->size);
              mainRect.setPosition(absolutePos);
              mainRect.setFillColor(fillColor);
              window.draw(mainRect);

              sf::Text text;
              text.setFont(*GameResources::getInstance().getFont("main"));
              text.setString(textString);
              text.setCharacterSize(24);
              text.setFillColor(sf::Color::White);
              text.setPosition(absolutePos + sf::Vector2f(10, 10));
              window.draw(text);
          }) {
    this->setVisible(visible);
}
