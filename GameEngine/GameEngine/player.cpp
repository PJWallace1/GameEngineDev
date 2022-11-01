#include "player.h"


Player::Player(float _x, float _y, float _w, float _h, int _hp, abilityType _a, string _spr):Obj(_x, _y, _w, _h) {
  ability = _a;
  hp = _hp;
  sprite = _spr;
}

float Player::getX() {
	return x;
}

void Player::setX(float posX) {
	this->x = posX;
}

float Player::getY() {
	return y;
}

void Player::setY(float posY) {
	this->y = posY;
}

int Player::getHP() {
	return hp;
}

void Player::setHP(int hp) {
	this->hp = hp;
}

abilityType Player::getAbility() {
	return ability;
}

void Player::setAbility(abilityType ability) {
	this->ability = ability;
}

bool Player::operator== (const Player& other) {
	return id == other.id;
}