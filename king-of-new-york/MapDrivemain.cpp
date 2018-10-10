#include <stdio.h>
#include <iostream>
#include <fstream>

#include "Map.h"
#include "Node.h"

using namespace std;

int main55()
{
	//Creating a new map with unconnected zones
	cout << "TEST CASE 1: Generating a map by manually coding Nodes and connecting them" << endl;
	Map exampleMap1 = Map::Map();
	Node* exZonei = new Node("Lower Manhatten", "Kong");
	Node* exZoneii = new Node("Midtown");
	Node* exZoneiii = new Node("Upper Manhatten");
	Node* exZoneiv = new Node("Bronx", "A Kraken");
	Node* exZonev = new Node("Queens");
	Node* exZonevi = new Node("Brookyln", "Codzilla");
	Node* exZonevii = new Node("Staten Island");

	exampleMap1.addRegion(exZonei);
	exampleMap1.addRegion(exZoneii);
	exampleMap1.addRegion(exZoneiii);
	exampleMap1.addRegion(exZoneiv);
	exampleMap1.addRegion(exZonev);
	exampleMap1.addRegion(exZonevi);
	exampleMap1.addRegion(exZonevii);

	exampleMap1.listAllZones();

	//connecting the zones of Manhatten to each other
	exZonei->connectZones(exZoneii);
	exZonei->connectZones(exZoneiv);
	exZonei->connectZones(exZonev);
	exZonei->connectZones(exZonevi);
	exZoneii->connectZones(exZoneiii);
	exZonev->connectZones(exZonevi);
	exZonei->printNeighbours();
	exZoneii->printNeighbours();
	exZoneiii->printNeighbours();
	exZoneiv->printNeighbours();
	exZonev->printNeighbours();
	cout << endl;

	//Testing Map loader
	cout << "TEST CASE 2: Reading from a file of specific format to generate a map" << endl;
	ifstream mapLayout("MapLayoutFormat1.txt"); //FILE NAME GIVEN HERE
	string xtraChars; //variable to read through unnecessary info
	string nextZoneName;
	Map exampleMap2 = Map::Map();
	Node* nextZone;
	//It is assumed that there are at least 2 zones in the map
		//and that there is at least one connection
	if (mapLayout.is_open())
	{
		getline(mapLayout, xtraChars);
		getline(mapLayout, nextZoneName);
		
		//create zones here
		while (nextZoneName != "Adjacent Zones:")
		{
			nextZone = new Node(nextZoneName);
			exampleMap2.addRegion(nextZone);
			getline(mapLayout, nextZoneName);

		}
		Node* connectedZone= nullptr;
		Node* adjacentZone;

		//Connects zones here
		xtraChars = mapLayout.get();
		while (xtraChars == "-")
		{
			getline(mapLayout, nextZoneName);
			//cout << "-" << nextZoneName<<endl;
			for (int i = 0; i < exampleMap2.getList().size(); i++)
			{
				if (nextZoneName == exampleMap2.getList().at(i)->getZoneName())
				{
					connectedZone = exampleMap2.getList().at(i);
				}
				
			}
			xtraChars = mapLayout.get();
			while (xtraChars == ">")
			{
				getline(mapLayout, nextZoneName);
				//cout <<  ">" << nextZoneName << endl;
				for (int i = 0; i < exampleMap2.getList().size(); i++)
				{
					if (nextZoneName == exampleMap2.getList().at(i)->getZoneName())
					{
						adjacentZone = exampleMap2.getZoneByName(nextZoneName);

						connectedZone->connectZones(adjacentZone);
						xtraChars = mapLayout.get();
					}
				}
			}
		}
		
		mapLayout.close();
	}
	exampleMap2.listAllZones();

	for (int i = 0; i < exampleMap2.getList().size(); i++)
	{
		exampleMap2.getList().at(i)->printNeighbours();
	}

	return 0;
}