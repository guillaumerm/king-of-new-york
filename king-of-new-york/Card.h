#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card {
protected:
	string name;
	string description;
public:
	Card();
	Card(string name, string description);
	string getName() const;
	string getDescription() const;
	void setName(string name);
	void setDescription(string description);
	friend ostream& operator<<(ostream&, const Card&);
};
#endif