#include "item.h"
#include <iostream>
#include <string>
using namespace std;

Item::Item(const char *name, const char *description, Entity *pather, ItemType item_type) 
	:Entity(name,description,pather),item_type(item_type)
{
	type = ITEM;
}

Item::~Item(){}

int Item::GetValue() const {
	return (int)item_type;
}

string Item::GetType(const ItemType item_type) const{
	switch (item_type)
	{
	case 0:
		return "COMMON";
	case 1:
		return "WEAPON";
	case 2:
		return "SHIELD";
	case 3:
		return "ARMOR";
	case 4:
		return "HELM";
	case 5:
		return "PANTS";
	case 6:
		return "GLOVES";
	case 7:
		return "BOOTS";
	default:
		return "NONE";
	}
}

void Item::Look()const {
	cout <<"Item "<< name <<": "<<description<<" typo ("<< GetType(item_type)<<")"<<endl;

}