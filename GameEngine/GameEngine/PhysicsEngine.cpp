#include <SFML/Graphics.hpp>
#include <vector>
#include "Obj.cpp"
#include <utility>
#include <iostream>

class PhysicsEngine
{
private:
  //Object vectors
  std::vector<Obj*> object; //gameObjects
  std::vector<Obj*> render; //renderable
  std::vector<Obj*> collide; //collidable
  std::vector<Obj*> move; //movable
  std::vector<std::pair<Obj*, Obj*>> collisions;

  bool checkCollision(Obj& o) {
    for (std::pair<Obj*, Obj*> p : collisions) {
      if ((*p.first).id == o.id || (*p.second).id == o.id) {
        return true;
      }
    }
    return false;
  }

public:
  void moveUp(float numPix, Obj& o) { o.r.move(0.f, -1 * numPix); }
  void moveLeft(float numPix, Obj& o) { o.r.move(-1 * numPix, 0.f); }
  void moveDown(float numPix, Obj& o) { o.r.move(0.f, numPix); }
  void moveRight(float numPix, Obj& o) { o.r.move(numPix, 0.f); }

  //Add elements to vectors
  void addToObjectVector(Obj& o) { object.push_back(&o); }
  void addToRenderVector(Obj& o) { render.push_back(&o); }
  void addToCollideVector(Obj& o) { collide.push_back(&o); }
  void addToMoveVector(Obj& o) { move.push_back(&o); }

  void renderScreen(sf::RenderWindow &window) {
    for (Obj* o : render) {
      window.draw((*o).r);
    }
  }

  void moveObjects() {
    for (Obj* o : move) {
      if (checkCollision(*o)) {
        (*o).r.setPosition((*o).x, (*o).y);
      }
      else {
        (*o).x = (*o).r.getPosition().x;
        (*o).y = (*o).r.getPosition().y;
      }
    }
  }

  void calculateCollisions() {
    collisions.clear();
    //Loop through array and compare all values to eachother
    for (int i = 0; i < collide.size(); i++) {
      for (int j = i + 1; j < collide.size(); j++) {
        //If the objects intersect
        if ((*collide[i]).r.getGlobalBounds().intersects((*collide[j]).r.getGlobalBounds())) {
          //Put the collision in a vector
          collisions.push_back(std::pair<Obj*, Obj*>(collide[i], collide[j]));
        }
      }
    }
  }

};