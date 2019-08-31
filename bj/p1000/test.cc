#include <iostream>
#include <string>
#include <queue>
#include<utility>
using namespace std;


int main() {

	string word;
	cin >> word;
	int size = word.size();
	
	//1st
	cout << "..#..";
	for (int i = 1;i < size;i++) {
		if ((i+1) %3 == 0) {
		cout << ".*..";
		}
		else {
			cout << ".#..";
		}
	}
	cout << "\n";

	//2nd
	cout << ".#.#.";
	for (int i = 1;i < size;i++) {
		if ((i + 1) % 3 == 0) {
			cout << "*.*.";
		}
		else {
			cout << "#.#.";
		}
	}
	cout << "\n";

	//3rd
	cout << "#";
	for (int i = 0;i < size;i++) {
		if ((i + 1) % 3 == 0) {
			cout << "*." << word[i] << ".*";
		}
		else if ((i + 2) % 3 == 0) {
			cout << "." << word[i] << ".#";
		}
		else if ((i + 3) % 3 == 0) {
			cout << "." << word[i] << ".#";
		}
	}
	cout << "\n";


	//4th
	cout << ".#.#.";
	for (int i = 1;i < size;i++) {
		if ((i + 1) % 3 == 0) {
			cout << "*.*.";
		}
		else {
			cout << "#.#.";
		}
	}
	cout << "\n";

	//5th
	cout << "..#..";
	for (int i = 1;i < size;i++) {
		if ((i + 1) % 3 == 0) {
			cout << ".*..";
		}
		else {
			cout << ".#..";
		}
	}
}