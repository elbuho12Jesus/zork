#include <string>
#include <vector>
#include <iostream>
#include <list>

using namespace std;
class Player;
class Entity;
class Word
{
public:
	Word();
	~Word();
	void readWord(vector<string> &player_vertor);
private:
	bool actions(vector<string> &player_vertor);
private:
	Player *player;
	list<Entity*> world;
};

