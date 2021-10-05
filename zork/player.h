#ifndef _PLAYER_
#define _PLAYER_

#include "creature.h"
class Room;
class Player :public Creature
{
public:
	Player(const char *name, const char *description, Room *room);
	~Player();
	void Look(const vector<string>& player_vector)const;
	void Go(const vector<string>& player_verctor);
	void Take(const vector<string>& player_vector);
	void Inventory(const vector<string>& player_vector)const;
	void Unlock(const vector<string>& player_vector);
};

#endif // !_PLAYER_