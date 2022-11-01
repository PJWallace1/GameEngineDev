#include <SFML/Graphics.hpp>
#include <vector>
#include "Obj.h"
#include <utility>
#include <iostream>

class PhysicsEngine
{
private:
  std::vector<std::pair<Obj*, Obj*>> collisions;

  bool checkCollision(Obj& o);

public:
  void moveUp(float numPix, Obj& o);
  void moveLeft(float numPix, Obj& o);
  void moveDown(float numPix, Obj& o);
  void moveRight(float numPix, Obj& o);


  void moveObjects(std::vector<Obj *>& movable);

  void calculateCollisions(std::vector<Obj *>& collidable);

};