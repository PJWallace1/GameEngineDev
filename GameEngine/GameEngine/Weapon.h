#pragma once
#include "Obj.h"
#include "Projectile.h"
class Weapon : public Obj
{
 protected:
  int ammoCount;
  sf::Clock reloadClock;
  int reloadTime;
  int damage;

  float shotSpeed;

public:
  Weapon(int _ammoCount, int _reloadTime, int _damage, float _shotSpeed);
  void fire(float mouseX, float mouseY);
};

