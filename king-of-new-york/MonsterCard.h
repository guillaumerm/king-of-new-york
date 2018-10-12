#ifndef MONSTER_CARD_H
#define MONSTER_CARD_H

#include <string.h>
#include "Card.h"

/** 
 * @brief A specification of Card. Introduces the life points and victory points concepts.
 */
class MonsterCard: public Card {
public:
	/**
	 * Parameterless constructor
	 */
	MonsterCard();
	
	/**
	 * A constructor which init name, description
	 * @param name name of the card
	 * @param description description of the card
	 */
	MonsterCard(std::string name, std::string description);

	/**
	 * A constructor which init name, description, lifePoints, victoryPoints
	 * @param name name of the card
	 * @param description description of the card
	 * @param lifePoints life points of the MonsterCard
	 * @param victoryPoints victory points of the MonsterCard
	 */
	MonsterCard(std::string name, std::string description, int lifePoints, int victoryPoints);
	
	/**
	 * Obtain the current life points of the MonsterCard
	 * @return life points of the MonsterCard
	 */
	int getLifePoint() const;

	/**
	 * Obtain the current victory points of the MonsterCard
	 * @return victory points of the MonsterCard
	 */
	int getVictoryPoint() const;

	/**
	 * Removes life points from the MonsterCard
	 * @param lifePoints number of life points to be removed
	 */
	void removeLifePoints(int lifePoints);

	/**
	 * Add life points from the MonsterCard
	 * @param lifePoints number of life points to be added
	 */
	void addLifePoints(int lifePoints);

	/**
	 * Add victory points from the MonsterCard
	 * @param victoryPoints number of life points to be added
	 */
	void addVictoryPoints(int victoryPoints);

	/**
	 * Removes victory points from the MonsterCard
	 * @param victoryPoints number of life points to be removed
	 */
	void removeVictoryPoints(int victoryPoints);
private:
	int lifePoints; /**< Life points of the MonsterCard*/
	int victoryPoints; /**< Victory points of the MonsterCard*/
	friend ostream& operator<<(ostream& strm, const MonsterCard&);
};
#endif
