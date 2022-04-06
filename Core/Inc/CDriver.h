/*
 * driver.h
 *
 *  Created on: Mar 4, 2022
 *      Author: Konra
 */

#ifndef INC_CDRIVER_H_
#define INC_CDRIVER_H_

#include "CHelper.h"
#include "CLed.h"
#include "CButton.h"
#include "GPIOs.h"
#include "CStateMachineLed.h"
#include "CHelper.h"
#include "CUartDriver.h"
#include "CControlLedByUart.h"

class CDriver
{

public:
	CDriver();
	~CDriver();

	void init();
	void update();


	static CUartDriver		m_uartDriver;

	static CLed 			LD2;

	static CLed 			m_redLed;
	static CLed 			m_blueLed;
	static CLed 			m_greenLed;

	static CButton			m_blueButton;
	static CStateMachineLed m_stateMachineLed;
	static CControlLedByUart m_controlLedByUart;


	static uint8_t driverBuffer[32];
	static uint8_t testValue;
};


#endif /* INC_CDRIVER_H_ */
