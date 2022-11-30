#pragma once
#include "Entity.h"
class EnemyMovementStrategy{
protected:
  vector<pair<float, float>> direction;
  int timer, maxTime, curIndex;
public:
  void move(Entity *enemy);
};

