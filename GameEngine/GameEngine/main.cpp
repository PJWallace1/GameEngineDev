#include <SFML/Graphics.hpp>

int main()
{
  sf::RenderWindow window(sf::VideoMode(200, 200), "Game Engine");
  window.setFramerateLimit(60);
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  while (window.isOpen())
  {
    sf::Event event;
    //while there are pending events
    while (window.pollEvent(event))
    {
      switch (event.type)
      {
        // window closed
        case sf::Event::Closed:
          window.close();
          break;
        // we don't process other types of events
        default:
          break;
      }
    }

    window.clear();
    window.draw(shape);
    window.display();
  }

  return 0;
}