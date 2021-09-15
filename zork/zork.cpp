// zork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

using namespace std;

void getVector(string &word, vector<string> &vector_player);

int main()
{
	char enter;
	string word;
	vector<string> vector_player;
	vector_player.reserve(10);
	vector_player.push_back("look");
	while (1) {
		if(_kbhit()!=0) 
		{
			enter = _getch();
			if (enter!='\r') 
			{				
				word += enter;
				cout << enter;
			}
			else 
			{
				getVector(word, vector_player);
			}
		}
		
		if (vector_player.size()>0 && vector_player[0]=="quit") 
		{
			break;
		}
		if (vector_player.size()>0) 
		{
			vector_player.clear();
			word = "";
			cout << "--> ";
		}
	}
	cout << vector_player[0] << endl;
	
	
}

void getVector(string &word,vector<string> &vector_player) {
	const char *cpword = word.c_str();
	do {
		const char *begin = cpword;
		while(*cpword!=' ' && *cpword) {
			cpword++;
		}
		vector_player.push_back(string(cpword,*begin));
	} while (0 != *cpword++);
}