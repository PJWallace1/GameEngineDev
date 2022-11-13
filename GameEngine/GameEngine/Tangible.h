#pragma once
#include "Obj.h"
class Tangible : public Obj
{
protected:
  float x, y;
  sf::RectangleShape r;

  Tangible(float _x, float _y, float _w, float _h);

public:
  void setX(float _x) { x = _x; }
  void setY(float _y) { y = _y; }
  void setR(sf::RectangleShape _r) { r = _r; }
  void setRPosition(float x, float y) { r.setPosition(x, y); }
  void moveR(float x, float y);

  float getX() { return x; }
  float getY() { return y; }
  sf::RectangleShape getR() { return r; }
};

