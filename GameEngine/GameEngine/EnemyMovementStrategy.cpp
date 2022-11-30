#include "EnemyMovementStrategy.h"

void EnemyMovementStrategy::move(Entity *enemy) {
  timer--;
  if (timer == 0) {
    timer = maxTime;
    curIndex = (curIndex + 1) % direction.size();
  }
  enemy->storePosition();
  float newX = direction[curIndex].first * enemy->getSpeed();
  float newY = direction[curIndex].second * enemy->getSpeed();
  enemy->moveR(newX, newY);
}