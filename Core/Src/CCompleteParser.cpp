/*
 * CCompleteParser.cpp
 *
 *  Created on: 7 kwi 2022
 *      Author: user
 */

#include "CCompleteParser.h"

CCompleteParser::CCompleteParser() {
	// TODO Auto-generated constructor stub

}

CCompleteParser::~CCompleteParser() {
	// TODO Auto-generated destructor stub
}

void CCompleteParser::init(CUartDriver* uartDriver, CLed* red, CLed* blue, CLed* green)
{
	m_uartDriver = uartDriver;
	m_red = red;
	m_blue = blue;
	m_green = green;
}

void CCompleteParser::update()
{

}

