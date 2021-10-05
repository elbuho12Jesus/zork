#ifndef _EXIT_
#define _EXIT_
#include "entity.h"
using namespace std;
class Room;
class Exit:public Entity
{
public:
	Exit(const char *name,const char *opposite_name,const char *description,Room *origin,Room *destination, bool one_way = false);
	~Exit();
	void Look()const;
	string &getNameFrom(const Room* room);
	Room *getDestinationFrom(const Room* room);
public:
	Room *destination;
	bool one_way;
	bool closed;
	bool locked;
	string opposite_name;
	Entity *key;
};

#endif // !_EXIT_



