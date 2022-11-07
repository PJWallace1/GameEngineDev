#include <map>
#include <iostream>
#include <queue>
#include "PhysicsEngine.h"
#include "jsonreader.h"

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

void renderScreen(sf::RenderWindow &window, std::vector<Obj*>& renderable) {
  for (Obj* o : renderable) {
    window.draw((*o).getR());
  }
}

int main()
{
  //Create the window and set the frame limit
  RenderWindow window(VideoMode(WINOW_W, WINDOW_H), "Game Engine");
  window.setFramerateLimit(FPS_LIMIT);

  //Object vectors
  std::vector<Obj*> objects; //gameObjects
  std::vector<Obj*> renderable; //renderable
  std::vector<Obj*> collidable; //collidable
  std::vector<Obj*> movable; //movable

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

  //A queue for processing method calls from key presses
  std::queue<MethodNames> processes;

  
  j.read(objects, renderable, collidable, movable);


  //Create a rectangle which represents a wall
  //Obj wall = createWall();

  
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
    //Iterates through an enum which contains all keys on a keyboard
    for (int k = Keyboard::A; k != Keyboard::KeyCount; k++) {
      //If a key is pressed
      if (Keyboard::isKeyPressed(static_cast<Keyboard::Key>(k))) {
        //Search for a correlated method call (represented as an enum) for that key within the keyBinds array
        //then add the correlated method call to a queue for processing
        processes.push(keyBinds[k]);
      }
    }
    //Process the method calls in the queue
    objects[PLYR]->setX(objects[PLYR]->getR().getPosition().x);
    objects[PLYR]->setY(objects[PLYR]->getR().getPosition().y);
    while (!processes.empty()) {
      switch(processes.front())
      {
      case moveUp:
        pe.moveUp(PLAYER_SPEED, objects[PLYR]);
        break;
      case moveDown:
        pe.moveDown(PLAYER_SPEED, *objects[PLYR]);
        break;
      case moveLeft:
        pe.moveLeft(PLAYER_SPEED, *objects[PLYR]);
        break;
      case moveRight:
        pe.moveRight(PLAYER_SPEED, *objects[PLYR]);
        break;
      default:
        break;
      }
      processes.pop();
    }

    pe.calculateCollisions(collidable);

    pe.moveObjects(movable);

    window.clear();
    renderScreen(window, renderable);
    window.display();
  }

  return 0;
}

/*
int main() {

  //stuff 1
  JSONReader j;
  vector<Obj*> objs;

  objs = j.read();

  cout << "Done" << endl;

  //stuff 2
  sf::RectangleShape a, b;

  b.setPosition(20, 30);

  a = b;

  b.setPosition(1, 2);

  return 0;
}
*/
