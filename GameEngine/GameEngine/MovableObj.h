#pragma once
#include "VisibleObj.h"
class MovableObj : public VisibleObj
{
protected:
  float prevX, prevY;

public:
  MovableObj(float _x, float _y, float _w, float _h, string _sprite);

  //All children can move, but in their own way
  virtual void move() {}

  float getPrevX() { return prevX; }
  float getPrevY() { return prevY; }

  void setPrevX(float _prevX) { prevX = _prevX; }
  void setPrevY(float _prevY) { prevY = _prevY; }
  //Stores the current values in the prev values
  void storePosition();
  void storeX();
  void storeY();
};

