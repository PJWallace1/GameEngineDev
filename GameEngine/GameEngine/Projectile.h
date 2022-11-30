#pragma once
#include "MovableObj.h"
class Projectile : public MovableObj
{
private:
  float angle;
  float speed;
  int damage;

public:
	Projectile(float _x, float _y, float _w, float _h, string _sprite, float _angle, float _speed, int _damage);

	void move();

  float getAngle() { return angle; }
  float getSpeed() { return speed; }

  void setAngle(float _angle) { angle = _angle; }
  void setSpeed(float _speed) { speed = _speed; }
};