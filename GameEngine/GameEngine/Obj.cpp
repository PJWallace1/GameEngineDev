#include <SFML/Graphics.hpp>

class Obj {
public:
  int x, y;
  int id;

  sf::RectangleShape r;

  Obj(sf::RectangleShape rec, int _x, int _y) {
    static int curID = 0;
    id = curID++;
    r = rec;
    x = _x;
    y = _y;
  }

  bool operator== (const Obj& other) {
    return id == other.id;
  }

  /*
  void setFutureX(int x) { futureX = x; }
  void setFutureY(int y) { futureX = y; }

  int getFutureX() { return futureX;  }
  int getFutureX() { return futureX; }
  */
};