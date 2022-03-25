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

//	struct SCommands
//	{
//		static constexpr char led_on[] {"LED_ON"};
//		static constexpr char led_off[] {"LED_OFF"};
//	};

	char led_on[7] {"LED_ON"};
	char led_off[8] {"LED_OFF"};
	void init(CUartDriver* uartDriver, CLed* led);
	void update();

private:

	//SCommands commands;

	CUartDriver* m_uartDriver;
	CLed* m_led;
};

#endif /* CCONTROLLEDBYUART_H_ */
