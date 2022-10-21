#include <SFML/Graphics.hpp>


class environmentObj {
private:
	int posX, posY;
	int id;
	float w, h;

	sf::RectangleShape r;

public:
	environmentObj(sf::RectangleShape rec, int x, int y, float _w, float _h) {
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

	bool operator== (const environmentObj& other) {
		return id == other.id;
	}
};