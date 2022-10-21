#include <iostream>
#include "Obj.cpp"
#include <fstream>

using namespace std;

class JSONReader {

	JSONReader() {

	}

	Obj read() {
		ifstream in;
		string inputLine;

		in.open("Source.txt");

		if (in.is_open()) {

			while(getline(in, inputLine)){
				if (inputLine == "{") {
					getline(in, inputLine);
				}
				

			}
		}
		else {
			cout << "Error, file not open." << endl;
		}
	}
};