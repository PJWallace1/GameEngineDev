#include "HorizontalEnemyMovementStrategy.h"

HorizontalEnemyMovementStrategy::HorizontalEnemyMovementStrategy() {
  direction.push_back(make_pair(0, 1));
  maxTime = 50;
  timer = maxTime;
  curIndex = 0;
}

