#pragma once
#include "MovableObj.h"
class Projectile : public MovableObj
{
private:
  float angle;
  float speed;
  int damage;
  //TODO: Add ownerID so doesnt damage owner

public:
	Projectile(float _x, float _y, float _w, float _h, string _sprite, float _angle, float _speed, int _damage);

	void move();

  float getAngle() { return angle; }
  float getSpeed() { return speed; }
  int getDamage() { return damage; }

  void setAngle(float _angle) { angle = _angle; }
  void setSpeed(float _speed) { speed = _speed; }

  bool processCollision(Tangible *other);
};