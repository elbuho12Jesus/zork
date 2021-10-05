#ifndef _CREATURE_
#define _CREATURE_

#include "entity.h"
#include <vector>
using namespace std;
class Room;
class Item;

class Creature :public Entity
{
public:
	Creature(const char *name, const char *description, Room *room);
	~Creature();
	virtual void Look(const vector<string>& player_vector) const;
	void Equip(const vector<string>& player_vector);
	void Drop(const vector<string>& player_vector);
	bool isLife()const;
	void DamageCalculation();
	void DefenseCalculation();
	void Attack(const vector<string>& player_vector);
	bool Fighting(Creature *taget);
public:
	int attack_base_max;
	int attack_base_min;	
	int life;
	int defense_base;	
	Item *weapon1;
	Item *weapon2;
	Item *helm;
	Item *armor;
	Item *pants;
	Item *gloves;
	Item *boots;
private:
	int attack_max;
	int attack_min;
	int defense;
};

#endif // !_CREATURE_
