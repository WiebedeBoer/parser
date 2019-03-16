#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	//regex (.+\w(?=\t))|(\d{4})|([^\[]+(?=\]))|([^\<]+(?=\>))|([^\{]+(?=\}))|((?<=\t)[^\t].+(?=[\s][(]\d{4}))
	ifstream file;
	ofstream outputFile;
	file.open("special-effects-companies.list");
	outputFile.open("output.txt");

	string line;
	string output;
	
	string seperator = "; ";
	char charArray[] = {'\"','\"', '(', ')','{','}','[',']','(',')'};

	if (file.is_open()) {
		while (getline(file, line)) {
			int valCount = 0;
			int charPos = 0;
			for (int i = 0; i < line.size(); i++) {
				if (line[i] == charArray[charPos]) {
					valCount++;
					i++;
					while (line[i] != charArray[charPos +1] && i < line.size()) {
						output += line[i];
						i++;
					}
					output += seperator;
					charPos = charPos + 2;
				}
				else if (line[i] == charArray[charPos + 2]) {
					output += "NULL" + seperator;
					valCount++;
					charPos = charPos + 2;
				}
			}
			output += "\n";
		}
		outputFile << output;

	}

	file.close();
	return 0;
}