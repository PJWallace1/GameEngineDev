#include "VisibleObj.h"

VisibleObj::VisibleObj(float _x, float _y, float _w, float _h, string _sprite):Tangible(_x, _y, _w, _h) {
  if (texture.loadFromFile(_sprite)) {
    texture.setRepeated(true);
    sprite.setTexture(texture);
    isTexture = true;
  }
  else {
    isTexture = false;
  }

}

void VisibleObj::draw(sf::RenderWindow &window) {
  if (isTexture) {
    sprite.setPosition(r.getPosition());
    window.draw(sprite);
  }
  else {
    window.draw(r);
  }
  
}