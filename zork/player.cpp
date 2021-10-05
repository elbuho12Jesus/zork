#include "room.h"
#include "player.h"
#include "exit.h"
#include "item.h"
#include "helper.h"
#include <iostream>
using namespace std;

Player::Player(const char *name, const char *description, Room *room) :Creature(name,description,room)
{
	type = PLAYER;
}

Player::~Player(){}

void Player::Look(const vector<string>& player_vector) const {
	if (player_vector.size()>1) 
	{
		if (player_vector.size()==2) 
		{
			if (helper::sameWord(player_vector[1],"me")) 
			{
				cout << name << endl;
				cout << description << endl;
				for (list<Entity*>::const_iterator it = container.begin(); it != container.cend();++it) 
				{
					Item *item = (Item*)(*it);
					item->Look();
				}
			}
			else {
				Entity *search = father->Find(player_vector[1]);
				if (search != NULL)
				{
					search->Look();
				}
				else 
				{
					cout << "this does not exist!" << endl;
				}
			}			
		}
		
			if (player_vector.size()==4) 
			{
				Entity *search = father->Find(player_vector[3]);
				if (search != NULL) 
				{
					Entity *internalSearch = search->Find(player_vector[1]);
					if (internalSearch != NULL) 
					{
						internalSearch->Look();
					}
					else {
						cout << "this does not exist in "<< search->name<<"!" << endl;
					}
				}
				else 
				{
					cout << "this does not exist!" << endl;
				}
			}
			
		
	}
	else {
		father->Look();
	}	
}

void Player::Go(const vector<string> &player_vector) {
	Exit *ex=(Exit*)father->Find(player_vector[1],EXIT);
	if (ex != NULL) {
		if (!ex->closed) 
		{
			father = ex->getDestinationFrom((Room*)this->father);
		}
		cout << "The Exit (" << ex->name << ") is blocked." << endl;
	}
	else 
	{
		cout << "This exit doesn't exist!" << endl;
	}
}

void Player::Take(const vector<string> &player_vector) {
	if (player_vector.size() == 4) {
		Entity *it = father->Find(player_vector[3], ITEM);
		if (it != NULL) {
			Entity *item = it->Find(player_vector[1], ITEM);
			if (item!=NULL) {
				this->container.push_back(item);
				item->father = this;
				it->container.remove(item);
			}
			else 
			{
				cout << "This item doesn't exist in "<< it->name <<"!" << endl;
			}
		}
		else 
		{
			cout << "This item doesn't exist!" << endl;
		}
	}
	else if(player_vector.size() == 2){
		Entity *it = father->Find(player_vector[1], ITEM);
		if (it != NULL) {
			this->container.push_back(it);
			it->father = this;
			father->container.remove(it);
		}
		else 
		{
			cout << "This item doesn't exist!" << endl;
		}
	}
	else {
		cout << "wrong syntax!" << endl;
	}
	
}

void Player::Inventory(const vector<string>& player_vector)const {
	if (weapon1 != NULL) {
		cout << "Weapon: " << weapon1->name << " Attack: " << weapon1->max_value << " ~ " << weapon1->min_value << endl;
	}
	if (weapon2 != NULL) {
		cout << "Shiel: " << weapon2->name << " Defense: " << weapon2->defense << endl;
	}
	if (armor != NULL) {
		cout << "Armor: " << armor->name << " Defense: " << armor->defense << endl;
	}
	if (helm != NULL) {
		cout << "Helm: " << helm->name << " Defense: " << helm->defense << endl;
	}
	if (pants != NULL) {
		cout << "Pants: " << pants->name << " Defense: " << pants->defense << endl;
	}
	if (gloves != NULL) {
		cout << "Gloves: " << gloves->name << " Defense: " << gloves->defense << endl;
	}
	if (boots != NULL) {
		cout << "Boots: " << boots->name << " Defense: " << boots->defense << endl;
	}	
	for (list<Entity*>::const_iterator it = container.begin(); it != container.cend();++it) {
		if (*it != (Entity*)weapon1 && *it != (Entity*)weapon2 && *it != (Entity*)armor && *it != (Entity*)helm && *it != (Entity*)pants && *it != (Entity*)gloves && *it != (Entity*)boots) {
			((Item*)(*it))->Look();
		}
	}
}

void Player::Unlock(const vector<string>& player_vector) {
	Exit* ex = (Exit*)father->Find(player_vector[2],EXIT);
	if (ex!=NULL ) 
	{
		if (ex->locked == true) 
		{
			ex->locked = false;
			cout << "Exit unlocked!" << endl;
		}
		else 
		{
			cout << "Exit unlocked!" << endl;
		}		
	}
	else 
	{
		cout << "This exit doesn't exist!" << endl;
	}
}