/*
 * button.cpp
 *
 *  Created on: Mar 2, 2022
 *      Author: Konra
 */



#include <CButton.h>


void CButton::init(GPIO_TypeDef* GpioPort, uint16_t GpioPin, uint32_t timerDebounce)
{
	this->GpioPort 	= GpioPort;
	this->GpioPin 	= GpioPin;
	m_timerDebounce = timerDebounce;
	state 			= idle;
}

void CButton::update()
{
	switch(state)
	{
		case idle:
			if(GPIO_PIN_RESET == HAL_GPIO_ReadPin(GpioPort, GpioPin))
			{
				state = debounce;
				m_lastTick = HAL_GetTick();
			}
			break;

		case debounce:
			if((HAL_GetTick() - m_lastTick) > m_timerDebounce)
			{
				if(GPIO_PIN_RESET == HAL_GPIO_ReadPin(GpioPort, GpioPin))
				{
					state = pressed;
					m_lastTick = HAL_GetTick();
				}
				else
				{
					state = idle;
				}
			}
			break;

		case pressed:
			if(GPIO_PIN_SET == HAL_GPIO_ReadPin(GpioPort, GpioPin))
			{
				state = idle;
			}
			break;
	}
}

void CButton::setTimerDobounce(uint32_t miliseconds)
{
	m_timerDebounce = miliseconds;
}

void CButton::setState(ButtonStates state)
{
	this->state = state;
}

CButton::ButtonStates CButton::getState()
{
	return state;
}


