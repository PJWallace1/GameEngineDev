#include <iostream>
#include "player.h"
#include "environmentObj.h"
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
  vector<Obj*> read(vector<Obj*>& objects, vector<Obj*>& renderable, vector<Obj*>& collidable, vector<Obj*>& movable);
};