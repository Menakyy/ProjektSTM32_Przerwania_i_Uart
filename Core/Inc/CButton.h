/*
 * button.h
 *
 *  Created on: Mar 2, 2022
 *      Author: Konra
 */

#ifndef INC_CBUTTON_H_
#define INC_CBUTTON_H_

#include "stm32f3xx_hal.h"
#include "GPIOs.h"

class CButton
{
public:

	enum ButtonStates
	{
		idle = 0,
		debounce = 1,
		pressed = 2,
	};

	void init(GPIO_TypeDef* GpioPort, uint16_t GpioPin, uint32_t timerDebounce);
	void update();

	void setTimerDobounce(uint32_t miliseconds);

	void setState(ButtonStates state);
	ButtonStates getState();

	void callBack(void* Callback());


private:
	GPIO_TypeDef* 	GpioPort;
	uint16_t		GpioPin;

	uint32_t		m_lastTick;
	uint32_t		m_timerDebounce;

	ButtonStates	state;

	void(*buttonPressed)(void);

};


#endif /* INC_CBUTTON_H_ */
