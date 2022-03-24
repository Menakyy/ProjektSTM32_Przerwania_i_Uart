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

void CControlLedByUart::init(CUartDriver* uartDriver, IGPIO* led)
{
	m_uartDriver = uartDriver;
	m_led = led;
}

void CControlLedByUart::update()
{
	if(m_uartDriver->parsing(commands.led_on))
	{

	}
	else if(m_uartDriver->parsing(commands.led_off))
	{

	}
}
