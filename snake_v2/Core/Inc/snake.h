#ifndef SNAKE_H_
#define SNAKE_H_

#include <stdio.h>
#include "main.h"
#include "tim.h"
#include "gpio.h"

#define SNAKE_MAX_LEN 64
#define GAME_DELAY 250

typedef struct Coord {
    int8_t x;
    int8_t y;
} Coord;

typedef struct Snake {
    int8_t length;
    Coord body[SNAKE_MAX_LEN];
    char direction;
} Snake; 

int8_t  change_direction(Snake *snake, char direction);
void clear_display(char display[]);
void  food_reached(Snake *snake, Coord *food);
int8_t move_head(Snake *snake);
int8_t  overlap_check(Snake *snake, Coord *position);
void random_food(Coord *food);
void set_screen(Coord *food, Snake *snake);
void update_tail(Snake *snake);
int8_t  wall_hit(Snake *snake);
void start_gameplay_snake(void);

extern char virtual_screen[8];

#endif // SNAKE_H_
