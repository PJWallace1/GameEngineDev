#include "environmentObj.h"

	environmentObj::environmentObj(float _x, float _y, float _w, float _h, string spr):Obj(_x, _y, _w, _h) {
    sprite = spr;
	}

	float environmentObj::getX() {
		return x;
	}

	void environmentObj::setX(float posX) {
		this->x = posX;
	}

	float environmentObj::getY() {
		return y;
	}

	void environmentObj::setY(float posY) {
		this->y = posY;
	}

	bool environmentObj::operator== (const environmentObj& other) {
		return id == other.id;
	}