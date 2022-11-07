#include "PhysicsEngine.h"

bool PhysicsEngine::checkCollision(Obj& o) {
  for (std::pair<Obj*, Obj*> p : collisions) {
    if ((*p.first).getId() == o.getId() || (*p.second).getId() == o.getId()) {
      return true;
    }
  }
  return false;
}


void PhysicsEngine::moveUp(float numPix, Obj* o) { (*o).moveR(0.f, -1 * numPix); }
void PhysicsEngine::moveLeft(float numPix, Obj& o) { o.moveR(-1 * numPix, 0.f); }
void PhysicsEngine::moveDown(float numPix, Obj& o) { o.moveR(0.f, numPix); }
void PhysicsEngine::moveRight(float numPix, Obj& o) { o.moveR(numPix, 0.f); }


void PhysicsEngine::moveObjects(std::vector<Obj *>& movable) {
  for (Obj* o : movable) {
    if (checkCollision(*o)) {
      (*o).setRPosition((*o).getX(), (*o).getY());
    }
    else {
      (*o).setX((*o).getR().getPosition().x);
      (*o).setY((*o).getR().getPosition().y);
    }
  }
}

void PhysicsEngine::calculateCollisions(std::vector<Obj *>& collidable) {
  collisions.clear();
  //Loop through array and compare all values to eachother
  for (int i = 0; i < collidable.size(); i++) {
    for (int j = i + 1; j < collidable.size(); j++) {
      //If the objects intersect
      if ((*collidable[i]).getR().getGlobalBounds().intersects((*collidable[j]).getR().getGlobalBounds())) {
        //Put the collision in a vector
        collisions.push_back(std::pair<Obj*, Obj*>(collidable[i], collidable[j]));
      }
    }
  }
}