/*
 * driver.cpp
 *
 *  Created on: Mar 4, 2022
 *      Author: Konra
 */


#include "CDriver.h"
#include "string.h"
#include "stdio.h"

uint8_t CDriver::driverBuffer[32];
uint8_t CDriver::testValue;


CUartDriver CDriver::m_uartDriver;

CLed CDriver::m_greenLed;
CButton CDriver::m_blueButton;
CStateMachineLed CDriver::m_stateMachineLed;

const char message[] = "test\r\n";

CDriver::CDriver()
{
}
CDriver::~CDriver()
{
}

void CDriver::init()
{
	m_uartDriver.init();

	m_greenLed.init(LD2_GPIO_Port, LD2_Pin, CLed::LedStates::toggle);
	m_blueButton.init(B1_GPIO_Port, B1_Pin, 20);
	m_stateMachineLed.init(&m_greenLed,&m_blueButton,&m_uartDriver);
}


void CDriver::update()
{
//	m_blueButton.update();
	m_greenLed.update();
//	m_stateMachineLed.update();





	//m_uartDriver.transmit((uint8_t*)message, strlen(message),500);

}
