/*
 * text.h
 *
 *  Created on: 27 sty 2020
 *      Author: PROJEKTOWY-MANA
 */

#ifndef INC_TEXT_H_
#define INC_TEXT_H_

#include <string.h>
#include "font3x5.h"
#include "snake.h"


char *text_buffer;
uint8_t display_buffer [300][8];

uint8_t test_screen[15][8] = {
		{1,1,1,1,0,1,0,1,0,1,0,0,1,1,1,1,1,0},
		{1,0,0,1,0,1,1,0,1,1,0,0,1,0,0,1,0,1},
		{1,1,1,1,1,0,1,0,1,1,0,0,1,1,1,1,0,1},
		{1,0,0,1,0,1,1,0,1,1,0,0,1,0,0,1,0,1},
		{1,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

uint8_t display_ascii();
void display_sign(uint8_t sign);
uint8_t get_letter_width (uint8_t *letter_shape);
void create_display_buffer(char *text);
void print(char *text);

#endif /* INC_TEXT_H_ */
