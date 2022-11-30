#include "player.h"


Player::Player(float _x, float _y, float _w, float _h, string _sprite, int _hp, AbilityType _ability, Speed _speed, Weapon *_weapon, int _gold):Entity(_x, _y, _w, _h, _sprite, _hp, _ability, _speed, _weapon) {
  gold = _gold;
  keyBinds[22] = moveUp;    //W
  keyBinds[0] = moveLeft;  //A
  keyBinds[18] = moveDown;  //S
  keyBinds[3] = moveRight; //D
}

void Player::move() {
	//Iterates through an enum which contains all keys on a keyboard
	for (int k = Keyboard::A; k != Keyboard::KeyCount; k++) {
		//If a key is pressed
		if (Keyboard::isKeyPressed(static_cast<Keyboard::Key>(k))) {
			//Search for a correlated method call (represented as an enum) for that key within the keyBinds array
			//then add the correlated method call to a queue for processing
			processes.push(keyBinds[k]);
		}
	}
	while (!processes.empty()) {
		switch (processes.front())
		{
		case moveUp:
			moveR(0.f, -1 * speed);
			break;
		case moveDown:
			moveR(0.f, speed);
			break;
		case moveLeft:
			moveR(-1 * speed, 0.f);
			break;
		case moveRight:
			moveR(speed, 0.f);
			break;
		default:
			break;
		}
		processes.pop();
	}
}

