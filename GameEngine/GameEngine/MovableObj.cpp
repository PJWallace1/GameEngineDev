#include "MovableObj.h"

MovableObj::MovableObj(float _x, float _y, float _w, float _h, string _sprite) : VisibleObj(_x, _y, _w, _h, _sprite) {
  prevX = _x;
  prevY = _y;
}

void MovableObj::storeX() {
  prevX = r.getPosition().x;
}
void MovableObj::storeY() {
  prevY = r.getPosition().y;
}

void MovableObj::storePosition() {
  storeX();
  storeY();
}