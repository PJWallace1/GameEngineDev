#include "Enemy.h"

Enemy::Enemy(float _x, float _y, float _w, float _h, string _sprite, int _hp, AbilityType _ability, Weapon *_weapon, MovementPattern _mp, AttackPattern _ap) :Entity(_x, _y, _w, _h, _sprite, _hp, _ability, _weapon) {
  ap = _ap;
  mp = _mp;
}