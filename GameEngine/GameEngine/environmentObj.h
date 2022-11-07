#include <SFML/Graphics.hpp>
#include "Obj.h"


class environmentObj : public Obj {
private:
  string sprite;

public:
  environmentObj(float _x, float _y, float _w, float _h, string spr);

  bool operator== (const environmentObj& other);

  string getSprite() { return sprite; }
  void setSprite(string _sprite) { sprite = _sprite; }
};