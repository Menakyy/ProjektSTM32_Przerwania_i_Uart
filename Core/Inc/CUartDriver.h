/*
 * CUartDriver.h
 *
 *  Created on: Mar 14, 2022
 *      Author: Konra
 */



#ifndef INC_CUARTDRIVER_H_
#define INC_CUARTDRIVER_H_


#include "stm32f3xx_hal.h"

class CUartDriver {
public:
	CUartDriver();
	virtual ~CUartDriver();

	static const uint8_t BUFFER_SIZE = 16;
	static const uint8_t RECEIVED_BUFFER_SIZE  = 32;

	enum BufferState
	{
	  BS_OK       = 0x00U,
	  BS_ERROR    = 0x01U,
	};

	uint8_t m_buffer[BUFFER_SIZE];
	uint8_t m_receivedBuffer[RECEIVED_BUFFER_SIZE];

	void init();
	void Error_Handler();

	void transmit(uint8_t *pData, uint16_t Size, uint32_t Timeout);
	void receive(uint8_t *pData, uint16_t Size, uint32_t Timeout);

	void transmitIT(uint8_t *pData, uint16_t Size);
	void receiveIT(uint8_t *pData, uint16_t Size);

	void irqRxComplete();
	void turnOnReceivingIfOff();

	BufferState writeToBuffer(uint8_t value);
	BufferState readFromBuffer(uint8_t* value);
	void Flush();
	void isEndLine(uint8_t value);
	void writeToReceivedBuffer();
	bool parsing(const char* command);

	UART_HandleTypeDef* getUart() {return &m_huart2;}


private:

	UART_HandleTypeDef m_huart2;

	uint16_t m_tail;
	uint16_t m_head;
	uint8_t m_dataReceive;
	uint8_t m_receivedLines;
	uint8_t m_tmpReceivedData;


	BufferState bufferState;
};

#endif /* INC_CUARTDRIVER_H_ */
