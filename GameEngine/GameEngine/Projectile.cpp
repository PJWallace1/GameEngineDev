#include "Projectile.h"

Projectile::Projectile(float _x, float _y, float _w, float _h, string _sprite, float _angle, float _speed, int _damage) :MovableObj(_x, _y, _w, _h, _sprite) {
  type = "Projectile";
  this->angle = _angle;
	this->speed = _speed;
	this->damage = _damage;
}

void Projectile::move() {
  //TODO
}

bool Projectile::processCollision(Tangible *other) {
  if (other->getType() != "Projectile") {
    return true;
  }
  return false;
}