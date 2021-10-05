#ifndef _ITEM_
#define _ITEM_

#include "entity.h"
enum ItemType {
	COMMON,
	WEAPON,
	SHIELD,
	ARMOR,
	HELM,
	PANTS,
	GLOVES,
	BOOTS
};
class Item : public Entity
{
public:
	Item(const char *name, const char *description, Entity *father, ItemType item_type = COMMON);
	~Item();

	virtual void Look() const;
	int GetValue() const;
	string GetType(const ItemType item_type) const;
public:
	int min_value;
	int max_value;
	int defense;	
	ItemType item_type;
};

#endif // !_ITEM_

