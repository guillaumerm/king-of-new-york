#include "Tile.h"

Tile::Tile(string name, string description, int durability) :Tile(name, description, durability, Tile::Type::Building) {}

Tile::Tile(string name, string description, int durability, Tile::Type type) {
	this->setName(name);
	this->setDescription(description);
	this->setDurability(durability);
	this->setType(type);
}

void Tile::setName(string name) {
	if (name.length() <= 0) {
		throw domain_error("Name cannot be empty string");
	}
	this->name = name;
}

void Tile::setDescription(string description) {
	if (description.length() <= 0) {
		throw domain_error("Description cannot be empty string");
	}
	this->description = description;
}

void Tile::setDurability(int durability) {
	if (durability <= 0) {
		throw domain_error("Durability must a non-zero positive integer");
	}
}

void Tile::setType(Tile::Type type) {
	this->type = type;
}

bool Tile::isUnit() const {
	return this->type == Tile::Type::Unit;
}

bool Tile::isBuilding() const {
	return this->type == Tile::Type::Building;
}

Tile::Type Tile::getType() const {
	return this->type;
}
int Tile::getDurability() const {
	return this->durability;
}

string Tile::getName() const {
	return this->name;
}

string Tile::getDescription() const {
	return this->description;
}

void Tile::removeDurability(int destructionPoints) {
	if (this->type == Type::Building) {
		if (durability - destructionPoints == 0) {
			this->type = Type::Unit;
		}
		else {
			throw domain_error("Not enough destructionPoints to destroy this building");
		}
	}
	else if(this->type == Type::Unit){
		if (durability - destructionPoints == 0) {
			//this->type == Type::Destroyed;
		}
		else {
			throw domain_error("Not enough destructionPoints to destroy this unit");
		}
	}
	else {
		throw exception("Tile is destroyed");
	}
}
