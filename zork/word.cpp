#include "word.h"
#include "helper.h"
#include "player.h"
#include "room.h"
#include "entity.h"
#include "exit.h"
#include "item.h"

Word::Word() {
	// room
	Room *coliseumOfHeroes = new Room("Coliseum_of_Heroes","coliseum where ancient knights fought to show courage.");
	world.push_back(coliseumOfHeroes);
	Room *forest = new Room("Forest_of_the_undead", "Here there are very dangerous monsters.");
	world.push_back(forest);
	// exit
	Exit *exitColiseumOfHeroes = new Exit("east", "west", "Exit to forest.", coliseumOfHeroes, forest);
	//item
	Item *rustySword = new Item("Rusty_Sword","Old rusty sword.",coliseumOfHeroes,WEAPON);
	rustySword->max_value = 10;
	rustySword->min_value = 8;
	world.push_back(rustySword);
	Item *stoneHammer = new Item("Stone_Hammer","great stone hammer old.",forest,WEAPON);
	stoneHammer->max_value = 13;
	stoneHammer->min_value = 10;
	world.push_back(stoneHammer);
	Item *box = new Item("Box","Secret Box.", coliseumOfHeroes);
	world.push_back(box);
	Item *key = new Item("Key","Key to unlock dungeon.",box);
	world.push_back(key);
	//creature
	Creature *mini_orc = new Creature("Mini_Orc","Orc meter and a half height.", coliseumOfHeroes);
	mini_orc->attack_base_max = 4;
	mini_orc->attack_base_min = 1;
	world.push_back(mini_orc);
	Creature *orc = new Creature("Orc","Green forest orc.", forest);
	orc->attack_base_max = 10;
	orc->attack_base_min = 7;
	world.push_back(orc);
	//player
	player = new Player("Hero", "The hero is looking for Zork to carry out his revenge.", coliseumOfHeroes);
	player->attack_base_max = 5;
	player->attack_base_min = 2;	
	player->life = 15;
	world.push_back(player);
}

Word::~Word() {
		
	for (list<Entity*>::const_iterator it = world.begin();it!=world.cend();++it)
	{
		delete *it;
	}
	world.clear();
}


void Word::readWord(vector<string> &player_vertor) 
{
	actions(player_vertor);
}

bool Word::actions(vector<string> &player_vertor) 
{
	switch (player_vertor.size())
	{
	case 1:
		if (helper::sameWord(player_vertor[0],"look")) 
		{
			player->Look(player_vertor);
			return true;
		}else if(helper::sameWord(player_vertor[0], "inventory"))
		{
			player->Inventory(player_vertor);
			return true;
		}
		else 
		{
			return false;
		}
	case 2:	
		if (helper::sameWord(player_vertor[0],"look"))
		{
			player->Look(player_vertor);
			return true;
		}
		else if (helper::sameWord(player_vertor[0], "go")) {
			player->Go(player_vertor);
			player->Look({});
			return true;
		} else if (helper::sameWord(player_vertor[0], "take")) {
			player->Take(player_vertor);
			return true;
		}
		else if (helper::sameWord(player_vertor[0], "equip")) {
			player->Equip(player_vertor);
			return true;
		}
		else if (helper::sameWord(player_vertor[0], "drop"))
		{
			player->Drop(player_vertor);
			return true;
		}
		else if (helper::sameWord(player_vertor[0], "attack"))
		{
			player->Attack(player_vertor);
			return true;
		}
		else 
		{
			return false;
		}	
	case 4:
		if (helper::sameWord(player_vertor[0], "look"))
		{
			player->Look(player_vertor);
			return true;
		}
		else if (helper::sameWord(player_vertor[0], "take"))
		{
			player->Take(player_vertor);
			return true;
		}
		else 
		{
			return false;
		}
		
	default:
		return false;
	}
	
}