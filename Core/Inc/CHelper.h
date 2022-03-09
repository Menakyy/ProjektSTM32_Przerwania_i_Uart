/*
 * CHelper.h
 *
 *  Created on: 9 mar 2022
 *      Author: Konra
 */

#ifndef INC_CHELPER_H_
#define INC_CHELPER_H_

#include "stm32f3xx_hal.h"
#include "main.h"
class CHelper
{


public:
	//inits
	static void init();
	static void SystemClock_Config(void);
	static void MX_GPIO_Init(void);
	static void MX_USART2_UART_Init(void);
	static void MX_NVIC_Init(void);

	//functions
	static void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
	static void Error_Handler();

	UART_HandleTypeDef huart2;
};



#endif /* INC_CHELPER_H_ */
