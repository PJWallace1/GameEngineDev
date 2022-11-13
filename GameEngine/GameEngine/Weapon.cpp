#include "Weapon.h"

Weapon::Weapon(int _ammoCount, int _reloadTime, int _damage, float _shotSpeed) :Obj() {
  ammoCount = _ammoCount;
  reloadTime = _reloadTime;
  damage = _damage;
  shotSpeed = _shotSpeed;
}