#include <SFML/Graphics.hpp>

const int WINOW_W = 1000;
const int WINDOW_H = 1000;
const int FPS_LIMIT = 60;
const float PLAYER_SPEED = 2;

using namespace sf;

int main()
{
  RenderWindow window(VideoMode(WINOW_W, WINDOW_H), "Game Engine");
  window.setFramerateLimit(FPS_LIMIT);
  RectangleShape rectangle;
  rectangle.setSize(sf::Vector2f(100, 50));
  rectangle.setOutlineColor(sf::Color::Red);
  rectangle.setOutlineThickness(5);
  rectangle.setPosition(10, 20);
  rectangle.setFillColor(Color::Green);

  while (window.isOpen())
  {
    Event event;
    //while there are pending events
    while (window.pollEvent(event))
    {
      switch (event.type)
      {
        // window closed
        case Event::Closed:
          window.close();
          break;
        // we don't process other types of events
        default:
          break;
      }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
      rectangle.move(PLAYER_SPEED, 0.f);
    } 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
      rectangle.move(PLAYER_SPEED * -1, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
      rectangle.move(0.f, PLAYER_SPEED * -1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
      rectangle.move(0.f, PLAYER_SPEED);
    }


    window.clear();
    window.draw(rectangle);
    window.display();
  }

  return 0;
}