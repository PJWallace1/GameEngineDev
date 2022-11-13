#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Player : public Entity {
private:
  int gold;

public:
  Player(float _x, float _y, float _w, float _h, string _sprite, int _hp, AbilityType _ability, Weapon *_weapon, int _gold);
};