#include <map>
#include <iostream>
#include <queue>
#include <set>
#include "PhysicsEngine.h"
#include "jsonreader.h"
#include "MovableObj.h"

//Window dimensions
const int WINOW_W = 1000;
const int WINDOW_H = 1000;
//Frame per second limit
const int FPS_LIMIT = 60;
//Players default speed
const float PLAYER_SPEED = 2;

const int PLYR = 0;

using namespace sf;

//loops from the objects in the renderable array and draws them to the screen
void renderScreen(sf::RenderWindow &window, std::vector<VisibleObj*>& renderable) {
  for (VisibleObj* o : renderable) {
    (*o).draw(window);
  }
}

void destroyObjects(std::set<Obj*>& destroy, std::vector<Obj*>& objects, std::vector<VisibleObj*>& renderable, std::vector<Tangible*>& collidable, std::vector<MovableObj*>& movable) {
  set<Obj*>::iterator itr;

  // Displaying set elements
  for (itr = destroy.begin(); itr != destroy.end(); itr++)
  {
    Obj* o = *itr;
    for (int i = 0; i < objects.size(); i++) {
      if (*o == *objects[i]) {
        if (o->getType() == "Player" || o->getType() == "Enemy") {
          objects.erase(objects.begin() + i); // erase weapon as well
        }
        objects.erase(objects.begin() + i);
        break;
      }
    }
    for (int i = 0; i < renderable.size(); i++) { 
      if (*o == *renderable[i]) {
        renderable.erase(renderable.begin() + i);
        break;
      }
    }
    for (int i = 0; i < collidable.size(); i++) {
      if (*o == *collidable[i]) {
        collidable.erase(collidable.begin() + i);
        break;
      }
    }
    if (o->getType() != "EnvironmentObj") {
      for (int i = 0; i < movable.size(); i++) {
        if (*o == *movable[i]) {
          movable.erase(movable.begin() + i);
          break;
        }
      }
    }
    delete o;
  }
  destroy.empty();
}

int main()
{
  //Create the window and set the frame limit
  RenderWindow window(VideoMode(WINOW_W, WINDOW_H), "Game Engine");
  window.setFramerateLimit(FPS_LIMIT);

  //Object vectors
  std::vector<Obj*> objects; //gameObjects
  std::vector<VisibleObj*> renderable; //renderable
  std::vector<Tangible*> collidable; //collidable
  std::vector<MovableObj*> movable; //movable
  std::set<Obj*> destroy;

  //An enum representing the possible methods a user can call through key presses
  enum MethodNames { null = -1, moveUp = 0, moveDown, moveRight, moveLeft };
  
  //An array which maps a key (represented as an enum/int which corresponds to an index) to a method name
  MethodNames keyBinds[100]{ null };
  keyBinds[22] = moveUp;    //W
  keyBinds[0]  = moveLeft;  //A
  keyBinds[18] = moveDown;  //S
  keyBinds[3]  = moveRight; //D

  PhysicsEngine pe;
  JSONReader j;
  j.read(objects, renderable, collidable, movable);
  
  while (window.isOpen())
  {
    Event event;
    //while there are pending events
    while (window.pollEvent(event))
    {
      switch (event.type)
      {
        // window closed
        case Event::Closed:
          window.close();
          break;
        // we don't process other types of events
        default:
          break;
      }
    }

    //Move all objects that want to move
    pe.moveObjects(movable);
    //Calculate collisions based on movement
    pe.calculateCollisions(collidable);
    //Process based on collisions
    destroy = pe.processCollisions(collidable);
    //Destroy objects which need to be destroyed
    destroyObjects(destroy, objects, renderable, collidable, movable);

    window.clear();
    renderScreen(window, renderable);
    window.display();
  }

  for (Obj *o : objects) {
    delete o;
  }

  return 0;
}

/*
int main() {

  //stuff 1
  JSONReader j;
  vector<pair<float, float>> output;

  output = j.parseForVectorOfFloatPairs("\"direction\": [[0, 2] [-2, 0] [0, -2] [2, 0]],");

  for (int i = 0; i < output.size(); i++) {
    cout << output[i].first << " " << output[i].second << endl;
  }
  return 0;
}
*/
