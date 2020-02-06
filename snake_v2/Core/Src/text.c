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
	uint8_t letter_width = 3;
	uint8_t shift = 3;
	for(uint8_t row=0; row<8; row++) {
		while(letter_shape[row] >> shift > 0) {
			if (shift > 3) letter_width = shift;
			shift++;
		}
	}
	return letter_width;
}

void create_display_buffer(char *text) {
	uint8_t letters_count = strlen(text); // sizeof(text) / sizeof(text[0]);

	for(uint8_t letter=0; letter<letters_count; letter++) {
		uint8_t current_letter = text[letter];
		uint8_t *letter_shape = font3x5[current_letter];
		uint8_t letter_width = get_letter_width(letter_shape);
		uint8_t letter_height = sizeof(letter_shape) / sizeof(letter_shape[0]);
		uint8_t col_offset = 0;
		for(uint8_t row=0; row<8; row++) {
			for(uint8_t col=letter_width; col>=0; --col) {
				uint8_t mask = 0b1 << col;
				if (row < letter_height) display_buffer[col+col_offset][row] = (letter_shape[row] && mask) >> col;
				else display_buffer[col+col_offset][row] = 0;
			}
			col_offset += letter_width;
		}
	}
}

void print(char *text) {
	create_display_buffer(text);

}
