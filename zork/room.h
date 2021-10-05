#ifndef _ROOM_
#define _ROOM_

#include "entity.h"

class Room :public Entity
{
public:
	Room(const char *name, const char *description);
	~Room();
	void Look() const;
};


#endif // !_ROOM_

