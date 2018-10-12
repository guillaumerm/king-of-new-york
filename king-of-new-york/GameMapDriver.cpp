#include "GameMap.h"
#include "GameMapNode.h"

#include <fstream>
#include <string.h>

using namespace std;

int main26()
{
	//Creating a new GameMap with unconnected zones
	cout << "TEST CASE 1: Generating a GameMap by manually coding GameMapNodes and connecting them" << endl;
	GameMap exampleGameMap1 = GameMap::GameMap();
	GameMapNode* exZonei = new GameMapNode("Lower Manhatten", "Kong");
	GameMapNode* exZoneii = new GameMapNode("Midtown");
	GameMapNode* exZoneiii = new GameMapNode("Upper Manhatten");
	GameMapNode* exZoneiv = new GameMapNode("Bronx", "A Kraken");
	GameMapNode* exZonev = new GameMapNode("Queens");
	GameMapNode* exZonevi = new GameMapNode("Brookyln", "Codzilla");
	GameMapNode* exZonevii = new GameMapNode("Staten Island");

	exampleGameMap1.addRegion(exZonei);
	exampleGameMap1.addRegion(exZoneii);
	exampleGameMap1.addRegion(exZoneiii);
	exampleGameMap1.addRegion(exZoneiv);
	exampleGameMap1.addRegion(exZonev);
	exampleGameMap1.addRegion(exZonevi);
	exampleGameMap1.addRegion(exZonevii);

	exampleGameMap1.listAllZones();

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

	//Testing GameMap loader
	cout << "TEST CASE 2: Reading from a file of specific format to generate a GameMap" << endl;
	ifstream mapLayout("new_york.map"); //FILE NAME GIVEN HERE
	string xtraChars; //variable to read through unnecessary info
	string nextZoneName;
	GameMap exampleGameMap2 = GameMap::GameMap();
	GameMapNode* nextZone;
	//It is assumed that there are at least 2 zones in the GameMap
		//and that there is at least one connection
	if (mapLayout.is_open())
	{
		getline(mapLayout, xtraChars);
		getline(mapLayout, nextZoneName);

		//create zones here
		while (nextZoneName != "Adjacent Zones:")
		{
			nextZone = new GameMapNode(nextZoneName);
			exampleGameMap2.addRegion(nextZone);
			getline(mapLayout, nextZoneName);

		}
		GameMapNode* connectedZone = nullptr;
		GameMapNode* adjacentZone;

		//Connects zones here
		xtraChars = mapLayout.get();
		while (xtraChars == "-")
		{
			getline(mapLayout, nextZoneName);
			//cout << "-" << nextZoneName<<endl;
			for (int i = 0; i < exampleGameMap2.getList().size(); i++)
			{
				if (nextZoneName == exampleGameMap2.getList().at(i)->getZoneName())
				{
					connectedZone = exampleGameMap2.getList().at(i);
				}

			}
			xtraChars = mapLayout.get();
			while (xtraChars == ">")
			{
				getline(mapLayout, nextZoneName);
				//cout <<  ">" << nextZoneName << endl;
				for (int i = 0; i < exampleGameMap2.getList().size(); i++)
				{
					if (nextZoneName == exampleGameMap2.getList().at(i)->getZoneName())
					{
						adjacentZone = exampleGameMap2.getZoneByName(nextZoneName);

						connectedZone->connectZones(adjacentZone);
						xtraChars = mapLayout.get();
					}
				}
			}
		}

		mapLayout.close();
	}
	if (exampleGameMap2.duplicateFree() && exampleGameMap2.allConnected())
	{
		exampleGameMap2.listAllZones();

		for (int i = 0; i < exampleGameMap2.getList().size(); i++)
		{
			exampleGameMap2.getList().at(i)->printNeighbours();
		}
	}
	else
	{
		cout << "Given map file is invalid" << endl;
		/*exampleGameMap2.listAllZones();

		for (int i = 0; i < exampleGameMap2.getList().size(); i++)
		{
			exampleGameMap2.getList().at(i)->printNeighbours();
		}*/

	}
	system("pause");
	return 0;
}
