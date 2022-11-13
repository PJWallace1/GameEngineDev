#include "Entity.h"

Entity::Entity(float _x, float _y, float _w, float _h, string _sprite, int _hp, AbilityType _ability, Weapon *_weapon) :VisibleObj(_x, _y, _w, _h, _sprite) {
  hp = _hp;
  ability = _ability;
  weapon = _weapon;
}