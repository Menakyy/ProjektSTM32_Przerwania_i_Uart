/*
 * CStateMachineLed.cpp
 *
 *  Created on: Mar 5, 2022
 *      Author: Konra
 */

#include <CStateMachineLed.h>
#include "string.h"
#include "stdio.h"



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

	if(button->getState() == CButton::pressed && led->getState() == CLed::on)
	{
		led->setState(CLed::off);

		//const char message[] = "Dioda wylaczona \r\n";
		//uart->transmit((uint8_t*)message, strlen(message), 500);
	}

	if(button->getState() == CButton::pressed && led->getState() == CLed::off)
	{
		led->setState(CLed::on);
	}

	if(button->getState() == CButton::pressed && led->getState() == CLed::toggle)
	{
		led->setState(CLed::toggle);
	}
}

