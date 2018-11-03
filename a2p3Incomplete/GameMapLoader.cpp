#include "GameMapLoader.h"

GameMap *GameMapLoader::loadMap(string filename) {
	ifstream mapLayout(filename); //FILE NAME GIVEN HERE
	string xtraChars; //variable to read through unnecessary info
	string nextZoneName;
	GameMap *map = new GameMap();
	GameMapNode* nextZone;
	//It is assumed that there are at least 2 zones in the map
		//and that there is at least one connection
	if (mapLayout.is_open())
	{
		getline(mapLayout, xtraChars);
		getline(mapLayout, nextZoneName);

		//create zones here
		while (nextZoneName != "Adjacent Zones:")
		{
			nextZone = new GameMapNode(nextZoneName);
			map->addRegion(nextZone);
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
			for (int i = 0; i < map->getList().size(); i++)
			{
				if (nextZoneName == map->getList().at(i)->getZoneName())
				{
					connectedZone = map->getList().at(i);
				}

			}
			xtraChars = mapLayout.get();
			while (xtraChars == ">")
			{
				getline(mapLayout, nextZoneName);
				//cout <<  ">" << nextZoneName << endl;
				for (int i = 0; i < map->getList().size(); i++)
				{
					if (nextZoneName == map->getList().at(i)->getZoneName())
					{
						adjacentZone = map->getZoneByName(nextZoneName);

						connectedZone->connectZones(adjacentZone);
						xtraChars = mapLayout.get();
					}
				}
			}
		}

		mapLayout.close();
	}

	return map;
}