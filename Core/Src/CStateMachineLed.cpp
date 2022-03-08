/*
 * CStateMachineLed.cpp
 *
 *  Created on: Mar 5, 2022
 *      Author: Konra
 */

#include <CStateMachineLed.h>

CStateMachineLed::CStateMachineLed() {
	// TODO Auto-generated constructor stub

}

CStateMachineLed::~CStateMachineLed() {
	// TODO Auto-generated destructor stub
}

void CStateMachineLed::init(CLed* led, CButton* button)
{
	this->led = led;
	this->button = button;
}

void CStateMachineLed::update()
{
	if(button->getState() == CButton::pressed && led->getState() == CLed::on)
	{
		led->turnOffLed();
	}

	if(button->getState() == CButton::pressed && led->getState() == CLed::off)
	{
		led->turnOnLed();
	}

	if(button->getState() == CButton::pressed && led->getState() == CLed::toggle)
	{
		led->togglePin();
	}
}
