#pragma once
#include "VisibleObj.h"
class Projectile : protected VisibleObj
{
private:
  float angle;
  float speed;

  void move();

public:
  Projectile(float _x, float _y, float _w, float _h, string _sprite, float _angle, float speed);

  float getAngle() { return angle; }
  float getSpeed() { return speed; }

  void setAngle(float _angle) { angle = _angle; }
  void setSpeed(float _speed) { speed = _speed; }
};

