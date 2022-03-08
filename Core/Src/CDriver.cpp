/*
 * driver.cpp
 *
 *  Created on: Mar 4, 2022
 *      Author: Konra
 */


#include "CDriver.h"


CLed CDriver::m_greenLed;


CButton CDriver::m_blueButton;
CStateMachineLed CDriver::m_stateMachineLed;


CDriver::CDriver()
{
}
CDriver::~CDriver()
{
}

void CDriver::init()
{
	m_greenLed.init(LD2_GPIO_Port, LD2_Pin, CLed::LedStates::toggle);

	m_blueButton.init(B1_GPIO_Port, B1_Pin, 20);

	m_stateMachineLed.init(&m_greenLed,&m_blueButton);
}


void CDriver::update()
{
	m_blueButton.update();
	m_greenLed.update();

	m_stateMachineLed.update();
}
