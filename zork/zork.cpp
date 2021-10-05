// zork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <cstddef>
#include "helper.h"
#include "word.h"

using namespace std;


void readSentences(string &vector_player) {

}
int main() {
	int initial = 1;
	string sentence;
	vector<string> vector_player;
	vector_player.reserve(10);
	Word word;
	vector_player.push_back("look");

	while (initial==1) {
		
		if (vector_player.size()>0) {
			word.readWord(vector_player);		
			vector_player.clear();
		}		
		
		cout << "--> ";
		getline(cin, sentence);
		helper::getVector(sentence, vector_player);
		if (helper::sameWord(vector_player[0] , "quit")) {
			initial=0;
		}

		

	}
	
	cout << "\nThanks for playing, Bye!"<<endl;
		
	return 0;
}