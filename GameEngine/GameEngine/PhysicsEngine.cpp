#include <SFML/Graphics.hpp>
#include <vector>
#include "Obj.cpp"
#include <utility>
#include <iostream>

class PhysicsEngine
{
private:
  std::vector<std::pair<Obj*, Obj*>> collisions;

  bool checkCollision(Obj& o) {
    for (std::pair<Obj*, Obj*> p : collisions) {
      if ((*p.first).id == o.id || (*p.second).id == o.id) {
        return true;
      }
    }
    return false;
  }

public:
  void moveUp(float numPix, Obj& o) { o.r.move(0.f, -1 * numPix); }
  void moveLeft(float numPix, Obj& o) { o.r.move(-1 * numPix, 0.f); }
  void moveDown(float numPix, Obj& o) { o.r.move(0.f, numPix); }
  void moveRight(float numPix, Obj& o) { o.r.move(numPix, 0.f); }


  void moveObjects(std::vector<Obj *>& movable) {
    for (Obj* o : movable) {
      if (checkCollision(*o)) {
        (*o).r.setPosition((*o).x, (*o).y);
      }
      else {
        (*o).x = (*o).r.getPosition().x;
        (*o).y = (*o).r.getPosition().y;
      }
    }
  }

  void calculateCollisions(std::vector<Obj *>& collidable) {
    collisions.clear();
    //Loop through array and compare all values to eachother
    for (int i = 0; i < collidable.size(); i++) {
      for (int j = i + 1; j < collidable.size(); j++) {
        //If the objects intersect
        if ((*collidable[i]).r.getGlobalBounds().intersects((*collidable[j]).r.getGlobalBounds())) {
          //Put the collision in a vector
          collisions.push_back(std::pair<Obj*, Obj*>(collidable[i], collidable[j]));
        }
      }
    }
  }

};