#include <map>
#include <iostream>
#include <queue>
#include "PhysicsEngine.cpp"


//Window dimensions
const int WINOW_W = 1000;
const int WINDOW_H = 1000;
//Frame per second limit
const int FPS_LIMIT = 60;
//Players default speed
const float PLAYER_SPEED = 2;

using namespace sf;

Obj createPlayer() {
  int x = 10, y = 20;
  RectangleShape rectangle;
  rectangle.setSize(sf::Vector2f(100, 50));
  rectangle.setOutlineColor(sf::Color::Red);
  rectangle.setOutlineThickness(5);
  rectangle.setPosition(10, 20);
  rectangle.setFillColor(Color::Green);
  return Obj(rectangle, x, y);
}

Obj createWall() {
  int x = 300, y = 300;
  RectangleShape rectangle;
  rectangle.setSize(sf::Vector2f(100, 50));
  rectangle.setOutlineColor(sf::Color::Yellow);
  rectangle.setOutlineThickness(5);
  rectangle.setPosition(300, 300);
  rectangle.setFillColor(Color::Blue);
  return Obj(rectangle, x, y);
}

int main()
{
  //Create the window and set the frame limit
  RenderWindow window(VideoMode(WINOW_W, WINDOW_H), "Game Engine");
  window.setFramerateLimit(FPS_LIMIT);

  //An enum representing the possible methods a user can call through key presses
  enum MethodNames { null = -1, moveUp = 0, moveDown, moveRight, moveLeft };
  
  //An array which maps a key (represented as an enum/int which corresponds to an index) to a method name
  MethodNames keyBinds[100]{ null };
  keyBinds[22] = moveUp;    //W
  keyBinds[0]  = moveLeft;  //A
  keyBinds[18] = moveDown;  //S
  keyBinds[3]  = moveRight; //D

  PhysicsEngine pe;

  //A queue for processing method calls from key presses
  std::queue<MethodNames> processes;

  //Create a rectangle which represents the player
  Obj player = createPlayer();

  //Create a rectangle which represents a wall
  Obj wall = createWall();

  pe.addToObjectVector(player);
  pe.addToObjectVector(wall);
  pe.addToRenderVector(player);
  pe.addToRenderVector(wall);
  pe.addToCollideVector(player);
  pe.addToCollideVector(wall);
  pe.addToMoveVector(player);


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
    player.x = player.r.getPosition().x;
    player.y = player.r.getPosition().y;
    while (!processes.empty()) {
      switch(processes.front())
      {
      case moveUp:
        pe.moveUp(PLAYER_SPEED, player);
        break;
      case moveDown:
        pe.moveDown(PLAYER_SPEED, player);
        break;
      case moveLeft:
        pe.moveLeft(PLAYER_SPEED, player);
        break;
      case moveRight:
        pe.moveRight(PLAYER_SPEED, player);
        break;
      default:
        break;
      }
      processes.pop();
    }

    pe.calculateCollisions();

    pe.moveObjects();

    window.clear();
    pe.renderScreen(window);
    window.display();
  }

  return 0;
}