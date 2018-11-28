#ifndef PHASE_OBSERVER_H
#define PHASE_OBSERVER_H
/**
 * @brief An interface that is used to declare the behavior that PhaseObserver will require to be able to observe PhaseSubject.
 */
class PhaseObserver {
public:
	/** 
	 * Signal the PhaseObserver that the registered PhaseSubject had its state changed.
	 */
	virtual void update() = 0;
};
#endif
