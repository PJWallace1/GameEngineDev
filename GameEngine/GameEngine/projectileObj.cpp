#include <SFML/Graphics.hpp>


class projectileObj {
private:
	int posX, posY;
	int id;
	float w, h;
	float speed;

	sf::RectangleShape r;

public:
	projectileObj(sf::RectangleShape rec, int x, int y, float _w, float _h) {
		static int curID = 0;
		id = curID++;
		r = rec;
		posX = x;
		posY = y;
		this->w = _w;
		this->h = _h;
	}

	int getX() {
		return posX;
	}

	void setX(int posX) {
		this->posX = posX;
	}

	int getY() {
		return posY;
	}

	void setY(int posY) {
		this->posY = posY;
	}


	float getSpeed() {
		return speed;
	}

	void setSpeed(float speed) {
		this->speed = speed;
	}


	bool operator== (const projectileObj& other) {
		return id == other.id;
	}
};