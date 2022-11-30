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
  void moveUp(float numPix, Tangible& o);
  void moveLeft(float numPix, Tangible& o);
  void moveDown(float numPix, Tangible& o);
  void moveRight(float numPix, Tangible& o);


  void moveObjects(std::vector<MovableObj *>& movable);

  void calculateCollisions(std::vector<Tangible *>& collidable);

  void processCollisions(std::vector<Tangible *>& collidable);

};