#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

//TODO: Make exist
enum MovementPattern {};
enum AttackPattern {};

class Enemy : public Entity {
private:
  int gold;
  MovementPattern mp;
  AttackPattern ap;

public:
  Enemy(float _x, float _y, float _w, float _h, string _sprite, int _hp, AbilityType _ability, Weapon *_weapon, MovementPattern _mp, AttackPattern _ap);

  MovementPattern getMovementPattern() { return mp; }
  AttackPattern getAttackPattern() { return ap; }

  void setMovementPattern(MovementPattern _mp) { mp = _mp; }
  void setAttackPattern(AttackPattern _ap) { ap = _ap; }
};