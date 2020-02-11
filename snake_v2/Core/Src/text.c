#include "text.h"

void display_sign(uint8_t sign) {
	sign = sign - ASCII_OFFSET;
	for (int row=0; row<5; row++)
	{
		uint8_t current_row = font3x5[sign][row];
		virtual_screen[row+1] = current_row;
	}
}

uint8_t display_ascii(void){
	uint8_t ascii_length = sizeof(font3x5) / sizeof(font3x5[0]);
	for (uint8_t sign=0; sign<ascii_length; sign++) {
		clear_display(virtual_screen);
		display_sign(sign + ASCII_OFFSET);
		HAL_Delay(250);
	}
	return 0;
}

uint8_t get_letter_width (uint8_t *letter_shape) {
	uint8_t letter_width = 0;
	for(uint8_t row=0; row<5; row++) {
		while((letter_shape[row] >> letter_width) > 0) {
			letter_width ++;
		}
	}
	return letter_width;
}

uint8_t create_display_buffer(char text[]) {
	uint8_t letters_count = strlen(text);
	uint8_t col_offset = 8;
	for(uint8_t col=0; col<8; col++) for(uint8_t row=0; row<8; row++) display_buffer[row][col] = 0;

	for(uint8_t letter=0; letter<letters_count; letter++) {
		uint8_t current_letter = text[letter];
		uint8_t *letter_shape = font3x5[current_letter - ASCII_OFFSET];
		uint8_t letter_width = get_letter_width(letter_shape);
		uint8_t letter_height = 5;

		for(uint8_t row=0; row<8; row++) {
			for(int8_t col=0; col<letter_width; col++) {
				uint8_t mask = 0b1 << (letter_width - 1 - col);

				if (row < letter_height) display_buffer[row][col+col_offset] = (letter_shape[row] & mask) >> (letter_width - 1 - col);
				else display_buffer[row][col+col_offset] = 0;
			}
		}
		col_offset += letter_width;
		for(uint8_t row=0; row<8; row++) display_buffer[row][col_offset] = 0;
		col_offset ++;
	}
	return col_offset;
}

void slice_display_buffer(uint8_t offset) {

	for(int8_t row=0; row<8; row++)
	{
		virtual_screen[row] = 0;
		for(uint8_t j=0; j<8; j++)
		{
			virtual_screen[row] |= (display_buffer[row][offset+j] << (7-j));
		}
	}
}


void print(char text[], uint32_t scroll_speed) {
	uint8_t string_len = create_display_buffer(text);
	for (uint8_t i=0; i<string_len; i++) {
		slice_display_buffer(i);
		HAL_Delay(scroll_speed);
	}
}
