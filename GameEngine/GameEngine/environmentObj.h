#pragma once
#include <SFML/Graphics.hpp>
#include "VisibleObj.h"

class EnvironmentObj : public VisibleObj {
private:

public:
  EnvironmentObj(float _x, float _y, float _w, float _h, string _sprite);
  bool processCollision(Tangible *other);
};