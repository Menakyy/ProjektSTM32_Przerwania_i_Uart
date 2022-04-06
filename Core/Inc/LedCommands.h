/*
 * LedCommands.h
 *
 *  Created on: 24 mar 2022
 *      Author: Konra
 */

#ifndef INC_LEDCOMMANDS_H_
#define INC_LEDCOMMANDS_H_


class CLedCommands
{
public:
	struct SCommands
	{
		char led_on[7] {"LED_ON"};
		char led_off[8] {"LED_OFF"};
	};

	SCommands commands;
};

#endif /* INC_LEDCOMMANDS_H_ */
