#include "jsonreader.h"


	JSONReader::JSONReader() {

	}

  string JSONReader::stripSpaces(string input) {
    string output = "";
    for (int i = 0; i < input.length(); i++) {
      if (input[i] != ' ') { output += input[i]; }
    }
    return output;
  }

  string JSONReader::parseForString(string input) {
    string output = "";
    int i = 0;
    input = stripSpaces(input);
    if (input.length() > 0) {
      while (input[i] != ':') {
        i++;
      }
      i+=2;
      for (int j = i; j < input.length() - 2; j++) {
        output += input[j];
      }
    }
    return output;
  }

  int JSONReader::parseForInt(string input) {
    string output = "";
    int i = 0;
    input = stripSpaces(input);
    if (input.length() > 0) {
      while (input[i] != ':') {
        i++;
      }
      i++;
      for (int j = i; j < input.length() - 1; j++) {
        output += input[j];
      }
    }
    return stoi(output);
  }

  float JSONReader::parseForFloat(string input) {
    string output = "";
    int i = 0;
    input = stripSpaces(input);
    if (input.length() > 0) {
      while (input[i] != ':') {
        i++;
      }
      i++;
      for (int j = i; j < input.length() - 1; j++) {
        output += input[j];
      }
    }
    return stof(output);
  }

  Weapon* JSONReader::parseWeapon(ifstream& in) {
    int ammoCount, reloadTime, damage;
    float shotSpeed;

    string inputLine;

    getline(in, inputLine);
    ammoCount = parseForInt(inputLine);
    getline(in, inputLine);
    reloadTime = parseForInt(inputLine);
    getline(in, inputLine);
    damage = parseForInt(inputLine);
    getline(in, inputLine);
    shotSpeed = parseForFloat(inputLine);

    Weapon *w = new Weapon(ammoCount, reloadTime, damage, shotSpeed);

    return w;
  }

  Player*  JSONReader::parsePlayer(ifstream& in) {
    float x, y, w, h;
    int hp;
    string spr;
    AbilityType a;
    Speed speed;
    Weapon *weapon;
    int gold;

    string inputLine;

    getline(in, inputLine);
    x = parseForFloat(inputLine);
    getline(in, inputLine);
    y = parseForFloat(inputLine);
    getline(in, inputLine);
    w = parseForFloat(inputLine);
    getline(in, inputLine);
    h = parseForFloat(inputLine);
    getline(in, inputLine);
    spr = parseForString(inputLine);
    getline(in, inputLine);
    hp = parseForInt(inputLine);
    getline(in, inputLine);
    a = static_cast<AbilityType>(parseForInt(inputLine));
    getline(in, inputLine);
    speed = static_cast<Speed>(parseForInt(inputLine));

    getline(in, inputLine);
    getline(in, inputLine);
    weapon = parseWeapon(in);
    getline(in, inputLine);

    getline(in, inputLine);
    gold = parseForInt(inputLine);

    Player *p = new Player(x, y, w, h, spr, hp, a, speed, weapon, gold);

    return p;
  }

  Enemy* JSONReader::parseEnemy(ifstream& in) {
    enum MovementPattern { HORIZONTAL, VERTICAL, CLOCKWISE, COUNTERCLOCKWISE };
    float x, y, w, h;
    int hp;
    string spr;
    AbilityType a;
    Weapon *weapon;
    Speed speed;
    EnemyMovementStrategy* ems;
    AttackPattern ap;
    int goldDropped;

    string inputLine;

    getline(in, inputLine);
    x = parseForFloat(inputLine);
    getline(in, inputLine);
    y = parseForFloat(inputLine);
    getline(in, inputLine);
    w = parseForFloat(inputLine);
    getline(in, inputLine);
    h = parseForFloat(inputLine);
    getline(in, inputLine);
    spr = parseForString(inputLine);
    getline(in, inputLine);
    hp = parseForInt(inputLine);
    getline(in, inputLine);
    a = static_cast<AbilityType>(parseForInt(inputLine));
    getline(in, inputLine);
    speed = static_cast<Speed>(parseForInt(inputLine));

    getline(in, inputLine);
    getline(in, inputLine);
    weapon = parseWeapon(in);
    getline(in, inputLine);

    getline(in, inputLine);
    MovementPattern mp = static_cast<MovementPattern>(parseForInt(inputLine));
    switch (mp) {
      case HORIZONTAL:
        ems = new HorizontalEnemyMovementStrategy();
        break;
      default:
        ems = new HorizontalEnemyMovementStrategy();
        break;
    }
    getline(in, inputLine);
    ap = static_cast<AttackPattern>(parseForInt(inputLine));
    getline(in, inputLine);
    goldDropped = parseForInt(inputLine);

    Enemy* e = new Enemy(x, y, w, h, spr, hp, a, speed, weapon, ems, ap, goldDropped);

    return e;
  }
  Projectile* JSONReader::parseProjectile(ifstream& in) {
    float x, y, w, h, angle, speed;
    int damage;
    string spr;

    string inputLine;

    getline(in, inputLine);
    x = parseForFloat(inputLine);
    getline(in, inputLine);
    y = parseForFloat(inputLine);
    getline(in, inputLine);
    w = parseForFloat(inputLine);
    getline(in, inputLine);
    h = parseForFloat(inputLine);
    getline(in, inputLine);
    spr = parseForString(inputLine);
    getline(in, inputLine);
    angle = parseForFloat(inputLine);
    getline(in, inputLine);
    speed = parseForFloat(inputLine);
    getline(in, inputLine);
    damage = parseForInt(inputLine);

    Projectile *p = new Projectile(x, y, w, h, spr, angle, speed, damage);
    return p;
  }
  EnvironmentObj* JSONReader::parseEnvironmentObj(ifstream &in) {
    float x, y, w, h;
    string spr;

    string inputLine;

    getline(in, inputLine);
    x = parseForFloat(inputLine);
    getline(in, inputLine);
    y = parseForFloat(inputLine);
    getline(in, inputLine);
    w = parseForFloat(inputLine);
    getline(in, inputLine);
    h = parseForFloat(inputLine);
    getline(in, inputLine);
    spr = parseForString(inputLine);

    EnvironmentObj *e = new EnvironmentObj(x, y, w, h, spr);

    return e;
  }

	vector<Obj*> JSONReader::read(vector<Obj*>& objects, vector<VisibleObj*>& renderable, vector<Tangible*>& collidable, vector<MovableObj*>& movable) {
		ifstream in;
		string inputLine, objType;
    vector<Obj*> createdObjs;

		in.open("Source.txt");

		if (in.is_open()) {

			while(getline(in, inputLine)){
        //cout << stripSpaces(inputLine) << endl;
				if (inputLine == "{") {
					getline(in, inputLine);
          objType = parseForString(inputLine);
          if (objType == "Player") {
            Player *p = parsePlayer(in);
            
            objects.push_back(p);
            objects.push_back(p->getWeapon());
            renderable.push_back(p);
            collidable.push_back(p);
            movable.push_back(p);
          }
          else if (objType == "EnvironmentObj") {
            EnvironmentObj *e = parseEnvironmentObj(in);

            objects.push_back(e);
            collidable.push_back(e);
            renderable .push_back(e);
          }
          else if (objType == "Enemy") {
            Enemy *e = parseEnemy(in);

            objects.push_back(e);
            objects.push_back(e->getWeapon());
            renderable.push_back(e);
            collidable.push_back(e);
            movable.push_back(e);
          }
          else if (objType == "Projectile") {
            Projectile *p = parseProjectile(in);

            objects.push_back(p);
            renderable.push_back(p);
            collidable.push_back(p);
            movable.push_back(p);
          }
				}
				

			}
		}
		else {
			cout << "Error, file not open." << endl;
		}

    return createdObjs;
	}