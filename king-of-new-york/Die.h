#ifndef DIE_H
#define DIE_H
class Die {
public:
	Die();
	enum class Face {
		A,	/**< Attack die face */
		C,	/**< Celebrity die face */
		D,	/**< Destruction die face */
		E,	/**< Energy die face */
		H,	/**< Heal die face */
		O	/**< Ouch! die face */
	};
	Face roll();
	Face getLastRoll() const;
private:
	Face lastRoll;
};
#endif
