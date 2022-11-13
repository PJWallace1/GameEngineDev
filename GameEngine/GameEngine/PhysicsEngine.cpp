#include "PhysicsEngine.h"

bool PhysicsEngine::checkCollision(Tangible& o) {
  for (std::pair<Tangible*, Tangible*> p : collisions) {
    if ((*p.first).getId() == o.getId() || (*p.second).getId() == o.getId()) {
      return true;
    }
  }
  return false;
}


void PhysicsEngine::moveUp(float numPix, Tangible& o) { o.moveR(0.f, -1 * numPix); }
void PhysicsEngine::moveLeft(float numPix, Tangible& o) { o.moveR(-1 * numPix, 0.f); }
void PhysicsEngine::moveDown(float numPix, Tangible& o) { o.moveR(0.f, numPix); }
void PhysicsEngine::moveRight(float numPix, Tangible& o) { o.moveR(numPix, 0.f); }


void PhysicsEngine::moveObjects(std::vector<Tangible *>& movable) {
  for (Tangible* o : movable) {
    if (checkCollision(*o)) {
      (*o).setRPosition((*o).getX(), (*o).getY());
    }
    else {
      (*o).setX((*o).getR().getPosition().x);
      (*o).setY((*o).getR().getPosition().y);
    }
  }
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