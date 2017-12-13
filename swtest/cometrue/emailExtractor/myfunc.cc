#include <filesystem>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <queue>

using namespace std;
using namespace std::experimental::filesystem;
namespace fs = std::experimental::filesystem;

string FILEREAD() { //FILE READ
	string input;
	cin >> input;
	int len = input.length();
	return input;
}
int check(string& line){ //CHECK EMAIL Line By Line
	int pos = line.find('@');
	int chk = 1, pos2=-1;
	if ((pos2=line.find('.',pos))!=-1) { // check if there exist dot '.' after at '@'
		// for case, both special characters exist but there is no letters between 
		// start of string and before at '@'
		if (pos == 0) return 0; 
			for (int i = 0; i < pos; i++) { // check validate between start of string and before at '@'
				if (!(('A' <= line[i] && line[i] <= 'Z')
				|| ('a' <= line[i] && line[i] <= 'z')
				|| ('0' <= line[i] && line[i] <= '9')
				|| '-' == line[i]
				|| '_' == line[i])) chk=0;
			}
			int chk2 = 1;
			if (chk) { // check validate between after at '@' before dot '.'
				// for case, there is no letters between after '@' before dot '.'
				if (pos + 1 == pos2) return 0;
				for (int i = pos + 1; i < pos2; i++) {
					if (!(('A' <= line[i] && line[i] <= 'Z')
					|| ('a' <= line[i] && line[i] <= 'z')
					|| ('0' <= line[i] && line[i] <= '9')))
					chk2 = 0;
				}
				chk = 1;
				if (chk2) { // check validate after dot '.'. 
										//now we make sure letters counting should be between 2~4
					int len = 0;
					for (int i = pos2 + 1; line[i]; i++, len++) {
						if (!(('A' <= line[i] && line[i] <= 'Z')
						|| ('a' <= line[i] && line[i] <= 'z')))
						chk = 0;
					}
				if (chk && (2 <= len && len <= 4)) return 1;
				}
			}
		}
	return 0;
}
