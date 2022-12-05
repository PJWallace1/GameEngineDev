#include "PhysicsEngine.h"

bool PhysicsEngine::checkCollision(Tangible& o) {
  for (std::pair<Tangible*, Tangible*> p : collisions) {
    if ((*p.first).getId() == o.getId() || (*p.second).getId() == o.getId()) {
      return true;
    }
  }
  return false;
}


void PhysicsEngine::moveObjects(std::vector<MovableObj *>& movable) {
  for (MovableObj* o : movable) {
    o->move();
  }
}

std::vector<std::pair<Tangible*, Tangible*>> PhysicsEngine::getCollisionsForCollidable(Tangible *o) {
  std::vector<std::pair<Tangible*, Tangible*>> collisionsSubset;
  for (std::pair<Tangible*, Tangible*> p : collisions) {
    if (*p.first == *o || *p.second == *o) {
      collisionsSubset.push_back(p);
    }
  }
  return collisionsSubset;
}

std::set<Obj*> PhysicsEngine::processCollisions(std::vector<Tangible *>& collidable) {
  std::set<Obj *> destroy;
    for (std::pair<Tangible*, Tangible*> p : collisions) {
      //Process the collision and destory it if needed
      if (p.first->processCollision(p.second)) { destroy.insert(p.first); }
      if (p.second->processCollision(p.first)) { destroy.insert(p.second); }
    }
  return destroy;
}

void PhysicsEngine::calculateCollisions(std::vector<Tangible *>& collidable) {
  collisions.clear();
  //Loop through array and compare all values to eachother
  for (int i = 0; i < collidable.size(); i++) {
    for (int j = i + 1; j < collidable.size(); j++) {
      //If the objects intersect
      if ((*collidable[i]).getR().getGlobalBounds().intersects((*collidable[j]).getR().getGlobalBounds())) {
        //Put the collision in a vector
        collisions.push_back(std::pair<Tangible*, Tangible*>(collidable[i], collidable[j]));
      }
    }
  }
}