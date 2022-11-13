#pragma once
#include <iostream>
#include <fstream>
#include "Player.h"
#include "EnvironmentObj.h"
#include "Enemy.h"
#include "Projectile.h"
#include "InteractableObj.h"

using namespace std;

class JSONReader {
public:
  JSONReader();

  string stripSpaces(string input);

  string parseForString(string input);
  int parseForInt(string input);
  float parseForFloat(string input);

  Player* parsePlayer(ifstream& in);
  Weapon* parseWeapon(ifstream& in);
  Enemy* parseEnemy(ifstream& in);
  Projectile* parseProjectile(ifstream& in);
  EnvironmentObj* parseEnvironmentObj(ifstream &in);

  //returns obj
  vector<Obj*> read(vector<Obj*>& objects, vector<VisibleObj*>& renderable, vector<Tangible*>& collidable, vector<Tangible*>& movable);
};