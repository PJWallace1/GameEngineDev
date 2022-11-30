#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Player.h"
#include "EnvironmentObj.h"
#include "Enemy.h"
#include "Projectile.h"
#include "InteractableObj.h"
#include "HorizontalEnemyMovementStrategy.h"

using namespace std;

class JSONReader {
public:
  JSONReader();

  string stripSpaces(string input);
  string stripColon(string input);
  string stripFrontEnd(string input, int front, int end);

  string parseForString(string input);
  int parseForInt(string input);
  float parseForFloat(string input);
  vector<pair<float, float>> parseForVectorOfFloatPairs(string input);
  vector<int> parseForVectorOfInts(string input);
  pair<float, float> parseForFloatPair(string input);

  Player* parsePlayer(ifstream& in);
  Weapon* parseWeapon(ifstream& in);
  Enemy* parseEnemy(ifstream& in);
  Projectile* parseProjectile(ifstream& in);
  EnvironmentObj* parseEnvironmentObj(ifstream &in);

  //returns obj
  vector<Obj*> read(vector<Obj*>& objects, vector<VisibleObj*>& renderable, vector<Tangible*>& collidable, vector<MovableObj*>& movable);
};