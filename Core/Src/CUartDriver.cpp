/*
 * CUartDriver.cpp
 *
 *  Created on: Mar 14, 2022
 *      Author: Konra
 */

#include <CUartDriver.h>

CUartDriver::CUartDriver() {
	// TODO Auto-generated constructor stub

}

CUartDriver::~CUartDriver() {
	// TODO Auto-generated destructor stub
}

void CUartDriver::init(UART_HandleTypeDef* m_uartDriver)
{
	this->m_uartDriver = m_uartDriver;
}

void CUartDriver::transmit(uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
	HAL_UART_Transmit(m_uartDriver, pData, Size, Timeout);
}



//HAL_StatusTypeDef CUartDriver::getHalStatus()
//{
//
//}
