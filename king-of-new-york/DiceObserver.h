#ifndef DICE_OBSERVER_H
#define DICE_OBSERVER_H
/**
 * @brief An interface that is used to declare the behavior that DiceObserver will require to be able to observe DiceSubject.
 */
class DiceObserver {
public:
	/**
	 * Signal the DiceObserver that the registered DiceSubject had its state changed.
	 */
	virtual void update() = 0;
};
#endif
