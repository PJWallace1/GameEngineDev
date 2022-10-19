#include <SFML/Graphics.hpp>

enum abilityType { heal, speed, strength };

class Player {
private:
	int posX, posY;
	int id;
	float w, h;
	int hp, speed, atkPow;
	abilityType ability;

	sf::RectangleShape r;

public:
	Player(sf::RectangleShape rec, int x, int y, float _w, float _h) {
		static int curID = 0;
		id = curID++;
		r = rec;
		posX = x;
		posY = y;
		this->w = _w;
		this->h = _h;
	}

	int getHP() {
		return hp;
	}

	void setHP(int hp) {
		this->hp = hp;
	}

	abilityType getAbility() {
		return ability;
	}

	void setAbility(abilityType ability) {
		this->ability = ability;
	}

	bool operator== (const Player& other) {
		return id == other.id;
	}
};