#include "environmentObj.h"

	environmentObj::environmentObj(float _x, float _y, float _w, float _h, string _spr):Obj(_x, _y, _w, _h) {
    sprite = _spr;
	}


	bool environmentObj::operator== (const environmentObj& other) {
		return id == other.id;
	}