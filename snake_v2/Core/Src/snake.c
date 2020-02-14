#include "snake.h"
#include <stdlib.h>


char virtual_screen[8] = {
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
};


int8_t change_direction(Snake *snake, char direction) {
    if (snake->direction == direction) return 0;
    else snake->direction = direction;
    button_pressed = 0;
    return 1;
}


void clear_display(char display[]){
    for (int i=0 ; i<8; i++) display[i] = 0b0;
};


void food_reached(Snake *snake, Coord *food){
	if(snake->body[0].x == food->x && snake->body[0].y == food->y) {
		snake->length++;
		int8_t overlap = -1;
		while (overlap == -1) {
			random_food(food);
			overlap = overlap_check(snake, food);
		}
	}
}


int8_t move_head(Snake *snake) {
    if (snake->direction == DOWN) snake->body[0].x ++;
    else if (snake->direction == UP) snake->body[0].x --;
    else if (snake->direction == LEFT) snake->body[0].y ++;
    else if (snake->direction == RIGHT) snake->body[0].y --;
    return overlap_check(snake, &snake->body[0]);
}



int8_t overlap_check(Snake *snake, Coord *position) {
    for (int i=1; i<SNAKE_MAX_LEN; i++) {
        if (snake->body[i].x == position->x && snake->body[i].y == position->y) return -1;
    }
    return 0;
}


void random_food(Coord *food) {
    food->x = rand() % 8;
    food->y = rand() % 8;
}


void set_screen(Coord *food, Snake *snake){
	virtual_screen[food->x] |= 1 << food->y;
	for (int k=0; k<SNAKE_MAX_LEN; k++)
	{
		virtual_screen[snake->body[k].x] |= 1 << snake->body[k].y;
	}
};


void update_tail(Snake *snake) {
    for(int i=snake->length; i>0; i--) {
        snake->body[i].x = snake->body[i-1].x;
        snake->body[i].y = snake->body[i-1].y;
    }
};


int8_t wall_hit(Snake *snake){
    if (snake->body[0].x < 0|| snake->body[0].x > 7 || snake->body[0].y < 0 || snake->body[0].y > 7) return -1;
    return 0;
}

void game_over_screen(Snake *snake, Coord *food){
	for (int8_t i = 0; i < 3; i ++) {
		clear_display(virtual_screen);
		HAL_Delay(150);
		set_screen(food, snake);
		HAL_Delay(150);
	}
	clear_display(virtual_screen);
}


void start_gameplay_snake(void) {
	while (game_over == 0) {
		Snake snake;
		snake.length = 0;
		snake.direction = UP;
		snake.body[0].x = 3, snake.body[0].y = 3;
		which_sw = UP;
		for (int i = 1; i < SNAKE_MAX_LEN; i++) {
			snake.body[i].x = -1, snake.body[i].y = -1;
		}

		Coord food;
		random_food(&food);

		int result = 0;

		print_center("3");
		HAL_Delay(250);
		print_center("2");
		HAL_Delay(250);
		print_center("1");

		HAL_Delay(250);

		set_screen(&food, &snake);

		while (result != -1) {

			HAL_Delay(GAME_DELAY - snake.length*6);

			change_direction(&snake, which_sw);

			update_tail(&snake);

			result = move_head(&snake); // overlap check
			if (result == -1) break;

			food_reached(&snake, &food); // hungry?

			result = wall_hit(&snake);

			HAL_Delay(GAME_DELAY/2);

			clear_display(virtual_screen);

			set_screen(&food, &snake);
		}


		game_over_screen(&snake, &food);

//		print_scroll("GAME OVER", 1, 75, SCROLL_LEFT);

//		print_scroll("SCORE", 1, 75, SCROLL_LEFT);
		char score[3];
		itoa(snake.length, score, 10);
		print_center(score);

	}

}
