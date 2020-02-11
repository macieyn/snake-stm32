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
	if (letter_width < 1) letter_width = 1;
	return letter_width;
}

uint8_t create_display_buffer(char text[]) {
	uint8_t letters_count = strlen(text);
	uint8_t col_offset = 8;
	for(uint8_t col=0; col<200; col++) for(uint8_t row=0; row<5; row++) display_buffer[row][col] = 0;

	for(uint8_t letter=0; letter<letters_count; letter++) {
		uint8_t current_letter = text[letter];
		uint8_t *letter_shape = font3x5[current_letter - ASCII_OFFSET];
		uint8_t letter_width = get_letter_width(letter_shape);
		uint8_t letter_height = 5;

		for(uint8_t row=0; row<5; row++) {
			for(int8_t col=0; col<letter_width; col++) {
				uint8_t mask = 0b1 << (letter_width - 1 - col);

				if (row < letter_height) display_buffer[row][col+col_offset] = (letter_shape[row] & mask) >> (letter_width - 1 - col);
				else display_buffer[row][col+col_offset] = 0;
			}
		}
		col_offset += letter_width;
		for(uint8_t row=0; row<5; row++) display_buffer[row][col_offset] = 0;
		col_offset ++;
	}
	return col_offset;
}

void slice_display_buffer(uint8_t offset, int8_t row_offset) {
	for(int8_t row=0; row<5; row++)
	{
		if ((row+row_offset <= 7) && (row+row_offset >= 0)) {
			virtual_screen[row+row_offset] = 0;
			for(uint8_t j=0; j<8; j++)
			{
				virtual_screen[row+row_offset] |= (display_buffer[row][offset+j] << (7-j));
			}
		}
	}
}


void print_scroll(char text[], int8_t row_offset, uint32_t scroll_speed, uint8_t scroll_direction) {
	uint8_t string_len = create_display_buffer(text);
	if (scroll_direction == 0) {
		for (uint8_t i=0; i<string_len; i++) {
			slice_display_buffer(i, row_offset);
			HAL_Delay(scroll_speed);
		}
	} else if (scroll_direction == 1) {
		for (uint8_t i=string_len; i>0; i--) {
			slice_display_buffer(i, row_offset);
			HAL_Delay(scroll_speed);
		}
	}
	clear_display(virtual_screen);
}

void print_center(char character[]) {
	uint8_t string_len = create_display_buffer(character);
//	char len[10];
//	itoa(string_len-8, len, 10);
//	print_scroll(len, 1, 100, SCROLL_RIGHT);
	if (string_len-8 > 5) slice_display_buffer(7, 1);
	else slice_display_buffer(5, 1);
	HAL_Delay(800);
	clear_display(virtual_screen);
}

void test_screen(void) {
	for (uint8_t i=0; i<8; i++) {
		for (uint8_t j=0; j<8; j++) {
			if (i == j) virtual_screen[j] = 0b11111111;
			else virtual_screen[j] = 0b0;
		}
		HAL_Delay(250);
	}
}
