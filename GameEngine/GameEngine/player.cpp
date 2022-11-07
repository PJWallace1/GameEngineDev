#include "player.h"


Player::Player(float _x, float _y, float _w, float _h, int _hp, abilityType _a, string _spr):Obj(_x, _y, _w, _h) {
  ability = _a;
  hp = _hp;
  sprite = _spr;
}

bool Player::operator== (const Player& other) {
	return id == other.id;
}