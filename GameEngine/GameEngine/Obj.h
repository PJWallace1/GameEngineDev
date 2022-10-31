#ifndef obj
#define obj
#include <SFML/Graphics.hpp>

using namespace std;

class Obj {
public:
  float x, y;
  int id;

  sf::RectangleShape r;

  Obj(float _x, float _y, float _w, float _h);

  bool operator== (const Obj& other);
  /*
  void setFutureX(int x) { futureX = x; }
  void setFutureY(int y) { futureX = y; }

  int getFutureX() { return futureX;  }
  int getFutureX() { return futureX; }
  */
};
#endif