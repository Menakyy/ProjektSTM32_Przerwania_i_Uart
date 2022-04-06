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

CLed CDriver::LD2;
CLed CDriver::m_redLed;
CLed CDriver::m_blueLed;
CLed CDriver::m_greenLed;

CButton CDriver::m_blueButton;




CStateMachineLed CDriver::m_stateMachineLed;
CControlLedByUart CDriver::m_controlLedByUart;



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

	LD2.init(LD2_GPIO_Port, LD2_Pin, CLed::LedStates::off);

	m_redLed.init(Reddiode_GPIO_Port, Reddiode_Pin, CLed::LedStates::off);
	m_blueLed.init(BlueDiode_GPIO_Port, BlueDiode_Pin, CLed::LedStates::off);
	m_greenLed.init(GreenDiode_GPIO_Port,GreenDiode_Pin,CLed::LedStates::off);

	//m_blueButton.init(B1_GPIO_Port, B1_Pin, 20);
	//m_stateMachineLed.init(&m_greenLed,&m_blueButton,&m_uartDriver);
	m_controlLedByUart.init(&m_uartDriver, &LD2);
}


void CDriver::update()
{

	LD2.update();
	m_redLed.update();
	m_blueLed.update();
	m_greenLed.update();
	//m_blueButton.update();
	//m_stateMachineLed.update();
	m_controlLedByUart.update();





	//m_uartDriver.transmit((uint8_t*)message, strlen(message),500);

}
