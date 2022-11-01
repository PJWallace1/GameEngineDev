#include <SFML/Graphics.hpp>


class interactableObj {
private:
	int posX, posY;
	int id, hp;
	float w, h;

	sf::RectangleShape r;

public:
	interactableObj(sf::RectangleShape rec, int x, int y, float _w, float _h) {
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

	int getHP() {
		return hp;
	}

	void setHP(int hp) {
		this->hp = hp;
	}



	bool operator== (const interactableObj& other) {
		return id == other.id;
	}
};