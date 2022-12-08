#pragma once
#include "Obj.h"
class Tangible : public Obj
{
protected:
  sf::RectangleShape r;

  Tangible(float _x, float _y, float _w, float _h);

public:
  void setR(sf::RectangleShape _r) { r = _r; }
  void setRPosition(float x, float y) { r.setPosition(x, y); }
  void moveR(float x, float y);

  float getX();
  float getY();
  sf::RectangleShape getR() { return r; }

  virtual bool processCollision(Tangible *other) = 0;
};

