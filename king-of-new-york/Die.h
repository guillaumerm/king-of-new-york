#ifndef DIE_H
#define DIE_H
/**
 * @brief Class which is used to roll random Die::Face
 */
class Die {
public:
	/**
	 * A parameterless contructor. It initializes the lastRoll with a random roll.
	 */
	Die();

	/**
	 * An enum which contains the symbols that a Die can roll
	 */
	enum class Face {
		A,	/**< Attack die face */
		C,	/**< Celebrity die face */
		D,	/**< Destruction die face */
		E,	/**< Energy die face */
		H,	/**< Heal die face */
		O,	/**< Ouch! die face */
		Face_MAX
	};

	/**
	 * Returns a randomly choosen Die::Face
	 * @return randomly selected Die::Face
	 */
	Face roll();

	/**
	 * Get the last randomly selected Die::Face
	 * @return the last Die::Face rolled
	 */
	Face getLastRoll() const;
private:
	Face lastRoll; /**< Last randomly roll Die::Face */
};
#endif
