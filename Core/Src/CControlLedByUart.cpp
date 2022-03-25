/*
 * CControlLedByUart.cpp
 *
 *  Created on: 24 mar 2022
 *      Author: Konra
 */

#include "CControlLedByUart.h"

CControlLedByUart::CControlLedByUart() {
	// TODO Auto-generated constructor stub

}

CControlLedByUart::~CControlLedByUart() {
	// TODO Auto-generated destructor stub
}

void CControlLedByUart::init(CUartDriver* uartDriver, CLed* led)
{
	m_uartDriver = uartDriver;
	m_led = led;
}

void CControlLedByUart::update()
{
	if(m_uartDriver->parsing(/*commands.*/led_on))
	{
		m_led->turnOnLed();
	}
	else if(m_uartDriver->parsing(/*commands.*/led_off))
	{
		m_led->turnOffLed();
	}
}
