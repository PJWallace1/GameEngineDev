#include "VisibleObj.h"

VisibleObj::VisibleObj(float _x, float _y, float _w, float _h, string _sprite):Tangible(_x, _y, _w, _h) {

}

void VisibleObj::draw(sf::RenderWindow &window) {
  window.draw(r);
}