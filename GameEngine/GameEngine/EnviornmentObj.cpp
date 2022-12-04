#include "environmentObj.h"

	EnvironmentObj::EnvironmentObj(float _x, float _y, float _w, float _h, string _sprite):VisibleObj(_x, _y, _w, _h, _sprite) {
    type = "EnvironmentObj";
	}

  bool EnvironmentObj::processCollision(Tangible *other) {
    return false;
  }