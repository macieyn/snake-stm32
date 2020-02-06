#ifndef SNAKE_H_
#define SNAKE_H_

#include <stdio.h>

#define UP 's'
#define DOWN 'w'
#define LEFT 'a'
#define RIGHT 'd'

typedef struct Coord {
    int8_t x;
    int8_t y;
} Coord;

typedef struct Snake {
    int8_t length;
    Coord body[64];
    char direction;
} Snake; 

int8_t  change_direction(Snake *snake, char direction);
void clear_display(char display[]);
int8_t  food_reached(Snake *snake, Coord *food);
int8_t move_head(Snake *snake);
int8_t  overlap_check(Snake *snake);
void random_food(Coord *food);
void set_screen(Coord *food, Snake *snake);
void update_tail(Snake *snake);
int8_t  wall_hit(Snake *snake);

extern char virtual_screen[8];

#endif // SNAKE_H_
