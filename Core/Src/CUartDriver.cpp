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

void CUartDriver::receive(uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
	HAL_UART_Receive(m_uartDriver, pData, Size, Timeout);
}

void CUartDriver::transmitIT(uint8_t *pData, uint16_t Size)
{
	HAL_UART_Transmit_IT(m_uartDriver, pData, Size);
}

void CUartDriver::receiveIT(uint8_t *pData, uint16_t Size)
{
	HAL_UART_Receive_IT(m_uartDriver, pData, Size);
}

CUartDriver::BufferState CUartDriver::writeToBuffer(uint8_t value)
{

	uint8_t tempHead = (m_head + 1) % BUFFER_SIZE;

	if(tempHead == m_tail)
	{
		return BufferState::BS_ERROR;
	}

	m_buffer[m_head] = value;
	m_head = tempHead;

	return BufferState::BS_OK;
}

CUartDriver::BufferState CUartDriver::readFromBuffer(uint8_t* value)
{
	if(m_head == m_tail)
	{
		return BufferState::BS_ERROR;
	}

	*value = m_buffer[m_tail];
	m_tail = (m_tail + 1) % BUFFER_SIZE;
	return BufferState::BS_OK;
}

void CUartDriver::Flush()
{
	m_head = 0;
	m_tail = 0;
}

void CUartDriver::irqRxComplete()
{
	writeToBuffer(m_dataReceive);
	HAL_UART_Receive_IT(m_uartDriver, &m_dataReceive, sizeof(m_dataReceive));

}
