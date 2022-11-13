#include "Projectile.h"

Projectile::Projectile(float _x, float _y, float _w, float _h, string _sprite, float _angle, float _speed, int _damage) :VisibleObj(_x, _y, _w, _h, _sprite) {
  angle = _angle;
  speed = _speed;
  damage = _damage;
}