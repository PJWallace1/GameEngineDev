#include "Enemy.h"

Enemy::Enemy(float _x, float _y, float _w, float _h, string _sprite, int _hp, AbilityType _ability, Speed _speed, Weapon *_weapon, MovementPattern _mp, AttackPattern _ap, int _gd) :Entity(_x, _y, _w, _h, _sprite, _hp, _ability, _speed, _weapon) {
  goldDropped = _gd;
  ap = _ap;
  mp = _mp;
}