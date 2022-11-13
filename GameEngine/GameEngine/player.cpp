#include "player.h"


Player::Player(float _x, float _y, float _w, float _h, string _sprite, int _hp, AbilityType _ability, Speed _speed, Weapon *_weapon, int _gold):Entity(_x, _y, _w, _h, _sprite, _hp, _ability, _speed, _weapon) {
  gold = _gold;
}