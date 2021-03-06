/*
 * driver.h
 *
 *  Created on: Mar 4, 2022
 *      Author: Konra
 */

#ifndef INC_CDRIVER_H_
#define INC_CDRIVER_H_


#include "CLed.h"
#include "CButton.h"
#include "GPIOs.h"
#include "CStateMachineLed.h"
class CDriver
{

public:
	CDriver();
	~CDriver();

	void init();
	void update();

	static CLed 			m_greenLed;

	static CButton			m_blueButton;
	static CStateMachineLed m_stateMachineLed;
};


#endif /* INC_CDRIVER_H_ */
