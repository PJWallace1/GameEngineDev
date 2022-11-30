#pragma once
#include "MovableObj.h"
#include "Weapon.h"

//Speed isn't being used for enemy rn
enum Speed { SLOW = 2, MEDIUM = 4, FAST = 8};

enum AbilityType { HEAL, SPEED, STRENGTH };

class Entity : public MovableObj
{
protected:
  int hp;
  AbilityType ability;
  Weapon *weapon;
  Speed speed;

public:
  Entity(float _x, float _y, float _w, float _h, string _sprite, int _hp, AbilityType _ability, Speed _speed, Weapon *_weapon);

  //All children can move, but in their own way
  virtual void move() {}

  int getHP() { return hp; }
  AbilityType getAbility() { return ability; }
  Weapon* getWeapon() { return weapon; }
  Speed getSpeed() { return speed; }

  void setHP(int _hp) { hp = _hp; }
  void setAbility(AbilityType _ability) { ability = _ability; }
  void setWeapon(Weapon* _weapon) { weapon = _weapon; }
  void setSpeed(Speed _speed) { speed = _speed; }
};

