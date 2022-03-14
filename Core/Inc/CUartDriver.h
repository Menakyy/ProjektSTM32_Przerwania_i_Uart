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

	void init(UART_HandleTypeDef* m_uartDriver);
	void transmit(uint8_t *pData, uint16_t Size, uint32_t Timeout);
	void receive();

	HAL_StatusTypeDef getHalStatus();

private:

	HAL_StatusTypeDef 		HalStatus;
	UART_HandleTypeDef* 	m_uartDriver;
};

#endif /* INC_CUARTDRIVER_H_ */
