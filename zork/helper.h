#include <string>
#include <vector>
#include <iostream>

using namespace std;

class helper
{
public:
	static void getVector(string &word, vector<string> &vector_player);
	static bool sameWord(const string &word1,const string &word2);
	static bool sameWord(const char *word1,const string &word2);
	static bool sameWord(const string &word1, const char *word2);
};

