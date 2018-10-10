
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include "Node.h"

using namespace std;


string const defaultRegion = "";
string const defaultOwner = "";
vector <Node*> adjacentZones;

Node::Node() :Node(defaultRegion, defaultOwner) {};

Node::Node(string region)
{
	regionName = region;
	regionOwner = "None";
}

Node::Node(string region, string initialOwner)
{
	regionName = region;
	regionOwner = initialOwner;
}

string Node::getZoneName() const
{
	return regionName;
}

string Node::getOwner() const
{
	return this->regionOwner;
}

void Node::newOwner(string usurper)
{
	regionOwner = usurper;
}

void Node::connectZones(Node* adjacentZone)
{
	//connectZones is called by one of the Nodes and the other as its parameter
	//connectZones adds both zones into each other's respective adjacentZone list
	adjacentZones.push_back(adjacentZone);
	adjacentZone->adjacentZones.push_back(this);
}

void Node::printNeighbours()
{
	if (adjacentZones.empty())
	{
		cout << "This region has no neighbours." << endl;
	}
	else
	{
		cout << regionName << " has ";
		for (int i = 0; i < adjacentZones.size(); i++)
		{
			cout << adjacentZones.at(i)->getZoneName() << ", ";
		}
		cout << "as its adjacent regions." << endl;
	}
}

