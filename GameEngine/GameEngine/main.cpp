#include <map>
#include <iostream>
#include <queue>
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
  Player *player;

  //A queue for processing method calls from key presses
  std::queue<MethodNames> processes;

  
  j.read(objects, renderable, collidable, movable);

  player = dynamic_cast<Player*>(objects[PLYR]);


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
    //player->storeX();
    //player->storeY();
    //while (!processes.empty()) {
    //  switch(processes.front())
    //  {
    //  case moveUp:
    //    pe.moveUp(PLAYER_SPEED, *player);
    //    break;
    //  case moveDown:
    //    pe.moveDown(PLAYER_SPEED, *player);
    //    break;
    //  case moveLeft:
    //    pe.moveLeft(PLAYER_SPEED, *player);
    //    break;
    //  case moveRight:
    //    pe.moveRight(PLAYER_SPEED, *player);
    //    break;
    //  default:
    //    break;
    //  }
    //  processes.pop();
    //}

    //Move all objects that want to move
    pe.moveObjects(movable);
    //Calculate collisions based on movement
    pe.calculateCollisions(collidable);
    //Process based on collisions
    //pe.processCollisions(collidable);

    

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
