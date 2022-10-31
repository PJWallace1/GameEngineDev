#include <SFML/Graphics.hpp>
#include "Obj.h"


class environmentObj : public Obj {
private:
  string sprite;

public:
  environmentObj(float _x, float _y, float _w, float _h, string spr);

  float getX();

  void setX(float posX);

  float getY();

  void setY(float posY);

  bool operator== (const environmentObj& other);
};