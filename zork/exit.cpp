#include "exit.h"
#include "room.h"
#include <string>
using namespace std;

Exit::Exit(const char *name, const char *opposite_name, const char *description, Room *origin, Room *destination, bool one_way) 
	:Entity(name,description,origin),opposite_name(opposite_name), destination(destination),one_way(one_way)
{
	type = EXIT;
	locked = false;
	this->destination->container.push_back(this);
}

Exit::~Exit(){}

void Exit::Look()const {
	cout<<"exit (" << name <<") ";
	cout << description << endl;
}

string &Exit::getNameFrom(const Room *room) {
	if (room==father) {
		return name;
	}
	if (room==destination) {
		return opposite_name;
	}
	return name;
}

Room *Exit::getDestinationFrom(const Room *room) {
	if (room==father) {
		return destination;
	}
	if(room==destination){
		return (Room*)father;
	}
	return destination;
}