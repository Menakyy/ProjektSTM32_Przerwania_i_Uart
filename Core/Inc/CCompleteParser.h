/*
 * CCompleteParser.h
 *
 *  Created on: 7 kwi 2022
 *      Author: user
 */

#ifndef CCOMPLETEPARSER_H_
#define CCOMPLETEPARSER_H_

#include "CUartDriver.h"
#include "CLed.h"

class CCompleteParser {
public:
	CCompleteParser();
	virtual ~CCompleteParser();

	static const uint8_t BUFFER_SIZE = 32;

	void init(CUartDriver* uartDriver, CLed* red, CLed* blue, CLed* green);
	void update();


private:

	uint8_t m_receivedBuffer[BUFFER_SIZE];

	CUartDriver* m_uartDriver;
	CLed* m_red;
	CLed* m_blue;
	CLed* m_green;

};

#endif /* CCOMPLETEPARSER_H_ */
