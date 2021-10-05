#include "creature.h"
#include "room.h"
#include "item.h"
#include <iostream>
#include <string>
using namespace std;

Creature::Creature(const char *name, const char *description, Room *room):Entity(name,description,room) {
	type = CREATURE;
	attack_base_max=0;
	attack_base_min=0;
	attack_max = attack_base_max;
	attack_min = attack_base_min;
	life=10;
	defense_base=2;
	defense = defense_base;
}

Creature::~Creature(){}

bool Creature::isLife()const {
	if (life <= 0) {		
		return false;
	}
	return true;
}

void Creature::Look(const vector<string>& player_vector) const{
	cout << name << endl;
	cout << description ;
	if (!this->isLife()) {
		cout << " (dead)";
	}
	cout << endl;
}

void Creature::Equip(const vector<string>& player_vector) {
	Item *item = (Item*)this->Find(player_vector[1],ITEM);
	if (item!=NULL) {
		switch (item->GetValue())
		{
		case 1:
			weapon1 = item;
			DamageCalculation();
			break;
		case 2:
			weapon2 = item;
			DefenseCalculation();
			break;
		case 3:
			armor = item;
			DefenseCalculation();
			break;
		case 4:
			helm = item;
			DefenseCalculation();
			break;
		case 5:
			pants = item;
			DefenseCalculation();
			break;
		case 6:
			gloves = item;
			DefenseCalculation();
			break;
		case 7:
			boots = item;
			DefenseCalculation();
			break;
		default:
			break;
		}
	}
}

void Creature::Drop(const vector<string>& player_vector) {
	Item *item = (Item*)this->Find(player_vector[1],ITEM);
	if (item!=NULL) {
		father->container.push_back(item);
		container.remove(item);
	}
}

void Creature::DamageCalculation() {
	if (weapon1!=NULL) {
		attack_max = attack_base_max + weapon1->max_value;
		attack_min = attack_base_min + weapon1->min_value;
	}
}

void Creature::DefenseCalculation() {
	if (weapon2 != NULL) {
		defense = defense_base + weapon2->defense;
	}
	if (armor != NULL) {
		defense = defense_base + armor->defense;
	}
	if (helm != NULL) {
		defense = defense_base + helm->defense;
	}
	if (pants != NULL) {
		defense = defense_base + pants->defense;
	}
	if (gloves != NULL) {
		defense = defense_base + gloves->defense;
	}
	if (boots != NULL) {
		defense = defense_base + boots->defense;
	}
}

void Creature::Attack(const vector<string>& player_vector) {
	Creature *target=(Creature*)father->Find(player_vector[1],CREATURE);
	bool fight = true;
	if (target!=NULL) 
	{	
		while (fight) 
		{
			if (fight) 
			{
				fight = Fighting(target);
			}
			
			if (fight) 
			{
				fight = target->Fighting(this);
			}
			
		}
		if (!target->isLife()) 
		{
			for (list<Entity*>::const_iterator it=target->container.begin();it!=target->container.cend();++it) 
			{
				target->Drop({"drop",(*it)->name});
			}
		}
	}
}

bool Creature::Fighting(Creature *target) {
	if (target->isLife() && this->isLife()) {
		int n = rand() % 100 + 1;
		int damage = defense - (attack_min + (attack_base_max - attack_min) / n);
		if (damage <0) {
			target->life = target->life + damage;
			cout << target->name << " life " << (target->life > 0) ? target->life : 0; 
			cout<< " received damage " << -damage << endl;
		}
		else {
			cout << target->name << " life " << target->life << " received damage 0"<< endl;
		}
		return true;
	}	
	return false;
	
}