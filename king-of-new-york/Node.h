#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Node {
private:
	string regionName;
	string regionOwner;
	vector <Node*> adjacentZones;

public:
	Node();
	Node(string);
	Node(string, string);

	string getZoneName() const;
	string getOwner() const;
	void newOwner(string);
	void connectZones(Node*);
	void printNeighbours();
};

#endif