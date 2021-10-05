#include "helper.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void helper::getVector(string &word, vector<string> &vector_player) {
	size_t space = 0;
	while (space != string::npos) {
		if (word.find_last_of(" ")== string::npos) {
			vector_player.push_back(word);
			space = string::npos;
		}
		else {
			if (space < word.find_last_of(" ")) {
				vector_player.push_back(string(word, space, word.find_first_of(" ", space) - space));
				space = word.find_first_of(" ", space) + 1;
			}
			else {
				vector_player.push_back(string(word, word.find_last_of(" ") + 1));
				space = string::npos;
			}
		}		
	}

}

bool helper::sameWord(const string &word1,const string &word2) {
	return _stricmp(word1.c_str(),word2.c_str())==0;
}
bool helper::sameWord(const char *word1,const string &word2) {
	return _stricmp(word1, word2.c_str())==0;
}

bool helper::sameWord(const string &word1,const char *word2) {
	return _stricmp(word1.c_str(), word2)==0;
}