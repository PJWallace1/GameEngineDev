#ifndef obj
#define obj
#include <SFML/Graphics.hpp>

using namespace std;

class Obj {
protected:
  float x, y;
  int id;

  sf::RectangleShape r;
public:
  Obj(float _x, float _y, float _w, float _h);

  bool operator== (const Obj& other);

  void setX(float _x) { x = _x; }
  void setY(float _y) { y = _y; }
  void setId(int _id) { id = _id; }
  void setR(sf::RectangleShape _r) { r = _r; }
  void setRPosition(float x, float y) { r.setPosition(x, y); }
  void moveR(float x, float y);

  float getX() { return x;  }
  float getY() { return y; }
  int getId() { return id; }
  sf::RectangleShape getR() { return r; }
};
#endif