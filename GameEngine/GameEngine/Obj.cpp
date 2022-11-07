#include "Obj.h"

Obj::Obj(float _x, float _y, float _w, float _h) {
  static int curID = 0;
  id = curID++;
  x = _x;
  y = _y;
  r.setPosition(_x, _y);
  r.setSize(sf::Vector2f(_w, _h));
}

bool Obj::operator== (const Obj& other) {
  return id == other.id;
}

void Obj::moveR(float x, float y) {
  r.move(x, y);
}
