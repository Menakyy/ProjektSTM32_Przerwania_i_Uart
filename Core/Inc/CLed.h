/*
 * CLed.h
 *
 *  Created on: Mar 4, 2022
 *      Author: Konra
 */

#ifndef INC_CLED_H_
#define INC_CLED_H_

#include "stm32f3xx_hal.h"
#include "IGPIO.h"

class CLed : public IGPIO
{

public:

	CLed();
	virtual ~CLed();

	enum LedStates
	{
		on,
		off,
		toggle
	};

	void init(GPIO_TypeDef* GpioPort, uint16_t GpioPin, LedStates state);
	virtual void update();

	void 		setState(LedStates state);
	LedStates 	getState();
	void 		setTimerToggle(uint32_t	timems);
	uint32_t	getTimerToggle();


	void 		togglePin();
	void 		turnOnLed();
	void 		turnOffLed();

private:
	GPIO_TypeDef* 	GpioPort;
	uint16_t		GpioPin;
	LedStates		state;
	uint32_t 		m_timerToggle;
	uint32_t		m_lastTick;
	bool			m_enter;
};

#endif /* INC_CLED_H_ */
