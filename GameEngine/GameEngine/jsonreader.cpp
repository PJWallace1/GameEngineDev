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

	vector<Obj*> JSONReader::read(vector<Obj*>& objects, vector<VisibleObj*>& renderable, vector<Tangible*>& collidable, vector<Tangible*>& movable) {
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
            double x, y, w, h;
            int hp;
            AbilityType a;
            string spr;

            getline(in, inputLine);
            x = parseForFloat(inputLine);
            getline(in, inputLine);
            y = parseForFloat(inputLine);
            getline(in, inputLine);
            w = parseForFloat(inputLine);
            getline(in, inputLine);
            h = parseForFloat(inputLine);
            getline(in, inputLine);
            hp = parseForInt(inputLine);
            getline(in, inputLine);
            a = static_cast<AbilityType>(parseForInt(inputLine));
            getline(in, inputLine);
            spr = parseForString(inputLine);
            

            Player *p = new Player(x, y, w, h, spr, hp, a, new Weapon(), 0);

            objects.push_back(p);
            renderable.push_back(p);
            collidable.push_back(p);
            movable.push_back(p);

          }
          else if (objType == "environmentObj") {
            double x, y, w, h;
            string spr;

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

            objects.push_back(e);
            collidable.push_back(e);
            renderable .push_back(e);

          }
				}
				

			}
		}
		else {
			cout << "Error, file not open." << endl;
		}

    return createdObjs;
	}