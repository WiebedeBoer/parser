#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ifstream file;
	ofstream outputFile;
	file.open("special-effects-companies.list");
	outputFile.open("test.txt");

	string line;
	string output;

	if (file.is_open()) {
		while (getline(file, line)) {
			for (char c : line) {
				int count = 0;
				if (c == '"') {
					while (line[count + 1] != '"') {
						output += line[count + 1];
						count++;
					}
					output += ", \n";
				}
				if (c == '(') {
					while (line[count + 1] != ')') {
						output += line[count + 1];
						count++;
					}
					output += ", \n";
				}
			}
		}
		outputFile << output;

	}

	file.close();
	return 0;
}