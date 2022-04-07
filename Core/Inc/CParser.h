/*
 * CParser.h
 *
 *  Created on: 7 kwi 2022
 *      Author: user
 */

#ifndef CPARSER_H_
#define CPARSER_H_

#include <stdint.h>
#include "CUartDriver.h"

class CParser {
public:
	CParser();
	virtual ~CParser();

	static const uint8_t RECEIVED_BUFFER_SIZE  = 32;

	void init(CUartDriver* uartDriver);

	void isEndLine(uint8_t value);
	void writeToReceivedBuffer();

private:
	uint8_t m_receivedBuffer[RECEIVED_BUFFER_SIZE];

	CUartDriver* m_uartDriver;
};

#endif /* CPARSER_H_ */
