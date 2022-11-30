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

  string JSONReader::stripColon(string input) {
    input = stripSpaces(input);
    string output = "";
    int i = 0;
    if (input.length() > 0) {
      while (input[i] != ':') {
        i++;
      }
      i++;
      while (i < input.length()) {
        output += input[i];
        i++;
      }
    }
    return output;
  }

  string JSONReader::stripFrontEnd(string input, int front, int end) {
    string output = "";
    //Validate input
    if (front < 0 || front >= input.length()) {
      front = 0;
    }
    if (end < 0 || end >= input.length()) {
      end = 0;
    }
    //Strip front/end
    if (front + end <= input.length()) {
      for (int i = front; i < input.length() - end; i++) {
        output += input[i];
      }
    }
    return output;
  }

  string JSONReader::parseForString(string input) {
    input = stripColon(input); //useless stuff
    input = stripFrontEnd(input, 1, 2); //quotes, comma
    return input;
  }

  int JSONReader::parseForInt(string input) {
    input = stripColon(input); //useless stuff
    input = stripFrontEnd(input, 0, 1); //comma
    return stoi(input);
  }

  float JSONReader::parseForFloat(string input) {
    input = stripColon(input); //useless stuff
    input = stripFrontEnd(input, 0, 1); //comma
    return stof(input);
  }
  
  vector<pair<float, float>> JSONReader::parseForVectorOfFloatPairs(string input) {
    vector<pair<float, float>> output;
    stringstream str;
    string pair;

    input = stripColon(input); //useless stuff
    input = stripFrontEnd(input, 1, 2); //square brackets, commas

    str << input;
    while (getline(str, pair, ']')) {
      pair = stripFrontEnd(pair, 1, 0); //front bracket
      output.push_back(parseForFloatPair(pair));
    }
    return output;
  }

  pair<float, float> JSONReader::parseForFloatPair(string input) {
    stringstream str;
    string x, y;

    str << input;
    getline(str, x, ',');
    str >> y;

    return make_pair(stof(x), stof(y));
  }
  
  vector<int> JSONReader::parseForVectorOfInts(string input) {
    vector<int> output;
    stringstream str;
    string myInt;

    input = stripColon(input); //useless stuff
    input = stripFrontEnd(input, 1, 2); //square brackets, commas

    str << input;
    while (getline(str, myInt, ',')) {
      output.push_back(stoi(myInt));
    }
    return output;
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
    vector <pair<float, float>> direction;
    vector<int> directionTime;
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
    direction = parseForVectorOfFloatPairs(inputLine);
    getline(in, inputLine);
    directionTime = parseForVectorOfInts(inputLine);
    getline(in, inputLine);
    ap = static_cast<AttackPattern>(parseForInt(inputLine));
    getline(in, inputLine);
    goldDropped = parseForInt(inputLine);

    Enemy* e = new Enemy(x, y, w, h, spr, hp, a, speed, weapon, direction, directionTime, ap, goldDropped);

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