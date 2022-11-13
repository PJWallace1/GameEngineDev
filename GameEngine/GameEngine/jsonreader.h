#pragma once
#include <iostream>
#include "Player.h"
#include "EnvironmentObj.h"
#include <fstream>

using namespace std;

class JSONReader {
public:
  JSONReader();

  string stripSpaces(string input);

  string parseForString(string input);

  int parseForInt(string input);

  float parseForFloat(string input);

  //returns obj
  vector<Obj*> read(vector<Obj*>& objects, vector<VisibleObj*>& renderable, vector<Tangible*>& collidable, vector<Tangible*>& movable);
};