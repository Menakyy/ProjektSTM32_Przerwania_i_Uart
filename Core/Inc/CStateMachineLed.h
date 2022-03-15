/*
 * CStateMachineLed.h
 *
 *  Created on: Mar 5, 2022
 *      Author: Konra
 */

#ifndef INC_CSTATEMACHINELED_H_
#define INC_CSTATEMACHINELED_H_


#include "CLed.h"
#include "CButton.h"
#include "CUartDriver.h"
#include "IGPIO.h"

class CStateMachineLed {
public:
	CStateMachineLed();
	virtual ~CStateMachineLed();


	void init(CLed* led, CButton* button, CUartDriver* uart);
	void update();

	void uartReceive();
	bool checkReceive();

	static uint8_t buffer[32];

private:
	CLed* 			led;
	CButton* 		button;
	CUartDriver* 	uart;


};

#endif /* INC_CSTATEMACHINELED_H_ */
