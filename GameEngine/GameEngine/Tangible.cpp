#include "Tangible.h"

Tangible::Tangible(float _x, float _y, float _w, float _h) {
  r.setPosition(_x, _y);
  r.setSize(sf::Vector2f(_w, _h));
}

void Tangible::moveR(float x, float y) {
  r.move(x, y);
}

float Tangible::getX() {
	return r.getPosition().x;
}
float Tangible::getY() {
	return r.getPosition().y;
}
