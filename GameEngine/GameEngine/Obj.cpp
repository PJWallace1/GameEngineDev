#include "Obj.h"

Obj::Obj() {
  static int curID = 0;
  id = curID++;
}

bool Obj::operator== (const Obj& other) {
  return id == other.id;
}
