/*
 * CParser.cpp
 *
 *  Created on: 7 kwi 2022
 *      Author: user
 */

#include "CParser.h"

CParser::CParser() {
	// TODO Auto-generated constructor stub

}

CParser::~CParser() {
	// TODO Auto-generated destructor stub
}

void CParser::init(CUartDriver* uartDriver)
{
	m_uartDriver = uartDriver;
}

void CParser::writeToReceivedBuffer()
{
	uint8_t Tmp;
	uint8_t i = 0;

	do
	{
		m_uartDriver->readFromBuffer(&Tmp);

		if(Tmp == '\n')
		{
			m_receivedBuffer[i] = 0;
		}
		else
		{
			m_receivedBuffer[i] = Tmp;
		}

		i++;
	}while(Tmp != '\n');
}
