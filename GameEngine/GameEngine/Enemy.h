#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

//TODO: Make exist
enum MovementPattern {HORIZONTAL, VERTICAL, CLOCKWISE, COUNTERCLOCKWISE};
enum AttackPattern {AUTOMATIC};

class Enemy : public Entity {
private:
  int goldDropped;
  MovementPattern mp;
  AttackPattern ap;

public:
  Enemy(float _x, float _y, float _w, float _h, string _sprite, int _hp, AbilityType _ability, Speed _speed, Weapon *_weapon, MovementPattern _mp, AttackPattern _ap, int _gd);

  int getGoldDropped() { return goldDropped; }
  MovementPattern getMovementPattern() { return mp; }
  AttackPattern getAttackPattern() { return ap; }

  void setGoldDropped(int _gd) { goldDropped = _gd; }
  void setMovementPattern(MovementPattern _mp) { mp = _mp; }
  void setAttackPattern(AttackPattern _ap) { ap = _ap; }
};