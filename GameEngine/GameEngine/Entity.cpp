#include "Entity.h"

Entity::Entity(float _x, float _y, float _w, float _h, string _sprite, int _hp, AbilityType _ability, Speed _speed, Weapon *_weapon) :MovableObj(_x, _y, _w, _h, _sprite) {
  hp = _hp;
  ability = _ability;
  weapon = _weapon;
  speed = _speed;

}

Entity::~Entity() {
  delete weapon;
}

bool Entity::takeDamage(int damage) {
  hp -= damage;
  if (hp <= 0) {
    return true;
  }
}