#pragma once
#include <SFML/Graphics.hpp>

using namespace std;

class Obj {
protected:
  int id;
  string type;
  
public:
  Obj();
  bool operator== (const Obj& other);

  void setId(int _id) { id = _id; }
  int getId() { return id; }
  string getType() { return type; }

  virtual void allowCast() {};
};