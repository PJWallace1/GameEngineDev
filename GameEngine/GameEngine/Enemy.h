#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "EnemyMovementStrategy.h"

//TODO: Make exist
enum AttackPattern {AUTOMATIC};

class Enemy : public Entity {
private:
  int goldDropped;
  AttackPattern ap;
  vector<pair<float, float>> direction;
  vector<int> directionTime;
  int timer, curIndex;

public:
  Enemy(float _x, float _y, float _w, float _h, string _sprite, int _hp, AbilityType _ability, Speed _speed, Weapon *_weapon, vector<pair<float, float>> _direction, vector<int> _directionTime, AttackPattern _ap, int _gd);

  void move();

  int getGoldDropped() { return goldDropped; }
  //MovementPattern getMovementPattern() { return mp; }
  AttackPattern getAttackPattern() { return ap; }

  void setGoldDropped(int _gd) { goldDropped = _gd; }
  //void setMovementPattern(MovementPattern _mp) { mp = _mp; }
  void setAttackPattern(AttackPattern _ap) { ap = _ap; }

  //Returns whether the objects needs to be destroyed
  bool processCollision(Tangible *other);
};