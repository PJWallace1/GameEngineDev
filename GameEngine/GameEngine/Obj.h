#pragma once
#include <SFML/Graphics.hpp>

using namespace std;

class Obj {
protected:
  int id;
  
public:
  Obj();
  bool operator== (const Obj& other);

  void setId(int _id) { id = _id; }
  int getId() { return id; }

  virtual void allowCast() {};
};