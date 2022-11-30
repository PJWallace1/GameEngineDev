#include "Enemy.h"

Enemy::Enemy(float _x, float _y, float _w, float _h, string _sprite, int _hp, AbilityType _ability, Speed _speed, Weapon *_weapon, vector<pair<float, float>> _direction, vector<int> _directionTime, AttackPattern _ap, int _gd) :Entity(_x, _y, _w, _h, _sprite, _hp, _ability, _speed, _weapon) {
  goldDropped = _gd;
  direction = _direction;
  directionTime = _directionTime;
  ap = _ap;
}

void Enemy::move() {
  //The player has moved
  if (timer == 0) {
    curIndex = (curIndex + 1) % direction.size();
    timer = directionTime[curIndex];
  }

  timer--;
  storePosition();
  moveR(direction[curIndex].first, direction[curIndex].second);
}