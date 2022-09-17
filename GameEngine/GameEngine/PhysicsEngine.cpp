#include <SFML/Graphics.hpp>
class PhysicsEngine
{
public:
  static void moveUp(float numPix, sf::RectangleShape& r) { r.move(0.f, -1 * numPix); }
  static void moveLeft(float numPix, sf::RectangleShape& r) { r.move(-1 * numPix, 0.f); }
  static void moveDown(float numPix, sf::RectangleShape& r) { r.move(0.f, numPix); }
  static void moveRight(float numPix, sf::RectangleShape& r) { r.move(numPix, 0.f); }
};