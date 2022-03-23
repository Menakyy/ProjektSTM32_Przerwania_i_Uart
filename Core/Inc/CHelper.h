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
	static void MX_NVIC_Init(void);

	//functions
	static void Error_Handler();



private:

};



#endif /* INC_CHELPER_H_ */
