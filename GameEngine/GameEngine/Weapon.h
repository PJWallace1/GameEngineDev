#pragma once
#include "Obj.h"
#include "Projectile.h"
class Weapon : public Obj
{
 protected:
  //Projectile p;
  int ammoCount;
  sf::Clock reloadClock;
  int reloadTime;

public:
  Weapon();
  void fire(float mouseX, float mouseY);
};

