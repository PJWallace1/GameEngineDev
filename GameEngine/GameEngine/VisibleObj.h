#pragma once
#include "Tangible.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
class VisibleObj : public Tangible
{
protected:
  sf::Sprite sprite;
  sf::Texture texture;

public:
  VisibleObj(float _x, float _y, float _w, float _h, string _sprite);
  void draw(sf::RenderWindow &window);

};

