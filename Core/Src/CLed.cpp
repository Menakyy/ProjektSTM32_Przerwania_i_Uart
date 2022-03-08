/*
 * CLed.cpp
 *
 *  Created on: Mar 4, 2022
 *      Author: Konra
 */

#include <CLed.h>

CLed::CLed() {
	// TODO Auto-generated constructor stub

}

CLed::~CLed() {
	// TODO Auto-generated destructor stub
}

void CLed::init(GPIO_TypeDef* GpioPort, uint16_t GpioPin, LedStates state = off)
{
	this->GpioPort 	= GpioPort;
	this->GpioPin 	= GpioPin;
	this->state 	= state;
	m_timerToggle 	= 500;
	m_enter 		= false;
}
void CLed::update()
{
	switch(state)
	{
		case on:
			turnOnLed();
			break;

		case off:
			turnOffLed();
			break;

		case toggle:
			if(m_enter == false)
			{
				m_lastTick = HAL_GetTick();
				m_enter = true;
			}


			if((HAL_GetTick() - m_lastTick) > m_timerToggle)
			{
				togglePin();
				m_enter = false;
			}

			break;
	}
}
void CLed::togglePin()
{
	HAL_GPIO_TogglePin(GpioPort, GpioPin);
}

void CLed::turnOnLed()
{
	HAL_GPIO_WritePin(GpioPort, GpioPin, GPIO_PIN_SET);
}

void CLed::turnOffLed()
{
	HAL_GPIO_WritePin(GpioPort, GpioPin, GPIO_PIN_RESET);
}

void CLed::setState(LedStates state)
{
	this->state = state;
}

CLed::LedStates CLed::getState()
{
	return state;
}

void CLed::setTimerToggle(uint32_t timems)
{
	m_timerToggle = timems;
}

uint32_t CLed::getTimerToggle()
{
	return m_timerToggle;
}
