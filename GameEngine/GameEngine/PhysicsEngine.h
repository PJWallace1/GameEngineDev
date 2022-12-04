#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"
#include <utility>
#include <iostream>

class PhysicsEngine
{
private:
  std::vector<std::pair<Tangible*, Tangible*>> collisions;

  bool checkCollision(Tangible& o);

public:

  void moveObjects(std::vector<MovableObj *>& movable);

  void calculateCollisions(std::vector<Tangible *>& collidable);

  //Returns a list of objects to destroy
  std::vector<Obj *> processCollisions(std::vector<Tangible *>& collidable);

  //Get the pairs from the collisions array which contain the given object
  std::vector<std::pair<Tangible*, Tangible*>> getCollisionsForCollidable(Tangible *collidable);

};