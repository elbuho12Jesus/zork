#include "room.h"
#include "item.h"
#include "exit.h"
#include "creature.h"
#include <iostream>
#include <string>
using namespace std;

Room::Room(const char *name,const char *description):Entity(name,description) {
	type = ROOM;
}

Room::~Room(){}

void Room::Look() const{
	cout << name << endl;
	cout << description << endl;
	
	for (list<Entity*>::const_iterator it = container.begin(); it != container.cend();++it) {
		//exits
		if ((*it)->type==EXIT) {
			Exit *exit = (Exit*)(*it);
			cout <<"Exit ("<< exit->getNameFrom(this) <<") to ";
			cout << exit->getDestinationFrom(this)->name << endl;
		}
		//creatures
		if ((*it)->type==CREATURE) {
			Creature *creature = (Creature*)(*it);
			cout << "There is a creature called (" << creature->name << "):";
			cout << creature->description;
			if (!creature->isLife())
			{
				cout << " (dead)";
			}
			cout << endl;
		}
		//items
		if ((*it)->type == ITEM) {
			Item *item = (Item*)(*it);
			cout << "There is a item called (" << item->name << "):";
			cout << item->description << endl;
		}
		
	}
}