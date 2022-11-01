#include <SFML/Graphics.hpp>
#include "Obj.h"

enum abilityType { heal, speed, strength };

class Player : public Obj {
private:
  int hp, speed, atkPow;
  abilityType ability;
  string sprite;

public:
  Player(float _x, float _y, float _w, float _h, int _hp, abilityType _a, string _spr);

  float getX();

  void setX(float posX);

  float getY();

  void setY(float posY);

  int getHP();

  void setHP(int hp);

  abilityType getAbility();

  void setAbility(abilityType ability);

  bool operator== (const Player& other);
};