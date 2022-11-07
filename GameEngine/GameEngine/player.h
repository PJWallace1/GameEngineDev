#include <SFML/Graphics.hpp>
#include "Obj.h"

enum abilityType { heal, speed, strength };

class Player : public Obj {
private:
  int hp, atkPow;
  abilityType ability;
  string sprite;

public:
  Player(float _x, float _y, float _w, float _h, int _hp, abilityType _a, string _spr);

  int getHP() { return hp; }

  void setHP(int _hp) { hp = _hp; }

  abilityType getAbility() { return ability; }

  void setAbility(abilityType _ability) { ability = _ability; }

  string getSprite() { return sprite; }
  void setSprite(string _sprite) { sprite = _sprite;  }

  bool operator== (const Player& other);
};