/*
 * CUartDriver.cpp
 *
 *  Created on: Mar 14, 2022
 *      Author: Konra
 */

#include <CUartDriver.h>
#include "string.h"
//UART_HandleTypeDef CUartDriver::m_huart2;

CUartDriver::CUartDriver() {
	// TODO Auto-generated constructor stub

}

CUartDriver::~CUartDriver() {
	// TODO Auto-generated destructor stub
}

void CUartDriver::init()
{
	m_huart2.Instance = USART2;
	m_huart2.Init.BaudRate = 38400;
	m_huart2.Init.WordLength = UART_WORDLENGTH_8B;
	m_huart2.Init.StopBits = UART_STOPBITS_1;
	m_huart2.Init.Parity = UART_PARITY_NONE;
	m_huart2.Init.Mode = UART_MODE_TX_RX;
	m_huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	m_huart2.Init.OverSampling = UART_OVERSAMPLING_16;
	m_huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
	m_huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
	if (HAL_UART_Init(&m_huart2) != HAL_OK)
	{
		Error_Handler();
	}

	turnOnReceivingIfOff();
}

void CUartDriver::irqRxComplete()
{
	if(writeToBuffer(m_dataReceive) == BS_OK)
	{
		isEndLine(m_dataReceive);
	}
	HAL_UART_Receive_IT(&m_huart2, &m_dataReceive, sizeof(m_dataReceive));
}

void CUartDriver::turnOnReceivingIfOff()
{
    if (m_huart2.gState == HAL_UART_STATE_READY || m_huart2.gState == HAL_UART_STATE_BUSY_TX)
    {
        HAL_UART_Receive_IT(&m_huart2, &m_dataReceive, sizeof(m_dataReceive));
    }
}

void CUartDriver::isEndLine(uint8_t value)
{
	if(value == '\n')
	{
		m_receivedLines++;
		writeToReceivedBuffer();
	}
}

void CUartDriver::writeToReceivedBuffer()
{
	uint8_t index = 0;
	do
	{
		readFromBuffer(&m_tmpReceivedData);
		if(m_tmpReceivedData == '\n')
		{
			m_receivedBuffer[index] = 0;
		}
		else
		{
			m_receivedBuffer[index] = m_tmpReceivedData;
		}
		index++;
	}while(m_tmpReceivedData != '\n');

	m_receivedLines--;

}

bool CUartDriver::parsing(const char* command)
{
	if(strcmp(command, (char*)m_receivedBuffer) == 0)
	{
		return true;
	}

	return false;
}

void CUartDriver::transmit(uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
	HAL_UART_Transmit(&m_huart2, pData, Size, Timeout);
}

void CUartDriver::receive(uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
	HAL_UART_Receive(&m_huart2, pData, Size, Timeout);
}

void CUartDriver::transmitIT(uint8_t *pData, uint16_t Size)
{
	HAL_UART_Transmit_IT(&m_huart2, pData, Size);
}

void CUartDriver::receiveIT(uint8_t *pData, uint16_t Size)
{
	HAL_UART_Receive_IT(&m_huart2, pData, Size);
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

void CUartDriver::Error_Handler()
{
	while(1)
	{

	}
}
