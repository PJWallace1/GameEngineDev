#pragma once
#include "VisibleObj.h"

//TODO: Make exist
enum Interaction {};

class InteractableObj : protected VisibleObj
{
protected:
  bool requiresInput;
  Interaction interaction;
  sf::RectangleShape hitbox;
  bool isVisible;

public:
  void activate();
};

