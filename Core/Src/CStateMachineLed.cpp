/*
 * CStateMachineLed.cpp
 *
 *  Created on: Mar 5, 2022
 *      Author: Konra
 */

#include <CStateMachineLed.h>
#include "string.h"
#include "stdio.h"


uint8_t CStateMachineLed::buffer[32];

CStateMachineLed::CStateMachineLed() {
	// TODO Auto-generated constructor stub

}

CStateMachineLed::~CStateMachineLed() {
	// TODO Auto-generated destructor stub
}

void CStateMachineLed::init(CLed* led, CButton* button, CUartDriver* uart)
{
	this->led 		= led;
	this->button 	= button;
	this->uart 		= uart;
}

void CStateMachineLed::update()
{
	//uartReceive();

	if(button->getState() == CButton::pressed && led->getState() == CLed::on /*&& checkReceive()*/)
	{
		led->turnOffLed();

//		const char message[] = "Dioda wylaczona \r\n";
//		uart->transmit((uint8_t*)message, strlen(message), 500);
	}

	if(button->getState() == CButton::pressed && led->getState() == CLed::off /*&& checkReceive()*/)
	{
		led->turnOnLed();
	}

	if(button->getState() == CButton::pressed && led->getState() == CLed::toggle)
	{
		led->togglePin();
	}
}

void CStateMachineLed::uartReceive()
{
	uart->receive(buffer, 1, 200);
}

bool CStateMachineLed::checkReceive()
{
	if(buffer[0] == 'o')
	{
		return true;
	}

	return false;
}
