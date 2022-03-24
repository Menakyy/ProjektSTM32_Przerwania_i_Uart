/*
 * CControlLedByUart.h
 *
 *  Created on: 24 mar 2022
 *      Author: Konra
 */

#ifndef CCONTROLLEDBYUART_H_
#define CCONTROLLEDBYUART_H_

#include "CUartDriver.h"
#include "CLed.h"
#include "LedCommands.h"

class CControlLedByUart
{
public:
	CControlLedByUart();
	virtual ~CControlLedByUart();

	struct SCommands
	{
		const char* led_on[] = "LED_ON";
		const char* led_off[] = "LED_OFF";
	};

	void init(CUartDriver* uartDriver, IGPIO* led);
	void update();

private:

	//static CLedCommands m_ledCommands;

	SCommands commands;

	CUartDriver* m_uartDriver;
	IGPIO* m_led;
};

#endif /* CCONTROLLEDBYUART_H_ */
