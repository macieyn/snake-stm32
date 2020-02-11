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
uint8_t display_buffer [8][200];

uint8_t display_ascii();
void display_sign(uint8_t sign);
uint8_t get_letter_width (uint8_t *letter_shape);
uint8_t create_display_buffer(char *text);
void print(char *text, uint32_t scroll_speed);
void slice_display_buffer(uint8_t offset);

#endif /* INC_TEXT_H_ */
