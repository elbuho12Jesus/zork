#include "entity.h"
#include "exit.h"
#include "helper.h"
#include <iostream>
#include <string>

using namespace std;

Entity::Entity(const char *name, const char *description, Entity *father):name(name),
description(description),father(father) {
	type = ENTITY;
	if (father!=NULL) {
		father->container.push_back(this);
	}
}

Entity::~Entity(){}

void Entity::Look() const{
	cout << name << endl;
	cout << description << endl;
}

bool Entity::Find(Entity *entidad) const {
	for (list<Entity*>::const_iterator it = container.begin(); it != container.cend();++it) {
		if ((*it)==entidad) {
			return true;
		}
	}
	return false;
}

Entity *Entity::Find(const string &name) const {
	for (list<Entity*>::const_iterator it = container.begin(); it != container.cend(); ++it) {
		if (helper::sameWord((*it)->name, name)) {
			return *it;
		}
	}
	return NULL;
}

Entity *Entity::Find(const string &name, Entity_type type) const {
	for (list<Entity*>::const_iterator it = container.begin(); it != container.cend(); ++it) {
		if (type==EXIT) {
			Exit *ex = (Exit*)(*it);
			if ((ex)->type == type && helper::sameWord((ex)->getNameFrom((Room*)this), name)) {
				return *it;
			}
		}
		else {
			if ((*it)->type == type && helper::sameWord((*it)->name, name)) {
				return *it;
			}
		}		
	}
	return NULL;
}