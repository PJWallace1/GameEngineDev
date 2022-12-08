#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <queue>

using namespace sf;

class Player : public Entity {
private:
  int gold;
  enum MethodNames { null = 0, moveUp, moveDown, moveRight, moveLeft };
  std::queue<MethodNames> processes;
  Player *player;
  //An array which maps a key (represented as an enum/int which corresponds to an index) to a method name
  MethodNames keyBinds[100]{ null };


public:

  Player(float _x, float _y, float _w, float _h, string _sprite, int _hp, AbilityType _ability, Speed _speed, Weapon *_weapon, int _gold);

  void move();

  //Returns whether the object needs to be destroyed
  bool processCollision(Tangible *other);

};