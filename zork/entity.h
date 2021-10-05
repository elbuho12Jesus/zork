#ifndef _ENTIRY_
#define _ENTIRY_

#include <iostream>
#include <list>
using namespace std;

enum Entity_type {
	ENTITY,
	ROOM,
	PLAYER,
	ITEM,
	CREATURE,
	EXIT
};

class Entity
{
public:
	Entity(const char *name, const char *description, Entity *father = NULL);
	virtual ~Entity();
	virtual void Look()const;
	bool Find(Entity *entidad) const;
	Entity *Find(Entity_type type) const;
	Entity *Find(const string &name) const;
	Entity *Find(const string &name, Entity_type type) const;
public:
	string name;
	string description;
	Entity_type type;
	Entity *father;
	list<Entity*> container;

};


#endif 

