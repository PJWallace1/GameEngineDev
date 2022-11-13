#pragma once
#include "VisibleObj.h"
#include "Weapon.h"

enum Speed { SLOW = 2, MEDIUM = 4, FAST = 8};

enum AbilityType { heal, speed, strength };

class Entity : public VisibleObj
{
protected:
  int hp;
  AbilityType ability;
  Weapon *weapon;
  Speed speed;

public:
  Entity(float _x, float _y, float _w, float _h, string _sprite, int _hp, AbilityType _ability, Weapon *_weapon);

  int getHP() { return hp; }
  AbilityType getAbility() { return ability; }
  Weapon* getWeapon() { return weapon; }
  Speed getSpeed() { return speed; }

  void setHP(int _hp) { hp = _hp; }
  void setAbility(AbilityType _ability) { ability = _ability; }
  void setWeapon(Weapon* _weapon) { weapon = _weapon; }
  void setSpeed(Speed _speed) { speed = _speed; }
};
