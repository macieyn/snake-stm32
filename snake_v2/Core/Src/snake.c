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
    return 1;
}


void clear_display(char display[]){
    for (int i=0 ; i<8; i++) display[i] = 0b0;
};


int8_t food_reached(Snake *snake, Coord *food){
//    for (int i=0; i<snake->length+1; i++) {
        if(snake->body[0].x == food->x && snake->body[0].y == food->y) return 1;
//    }
    return 0;
}


int8_t move_head(Snake *snake) {
    if (snake->direction == UP) snake->body[0].x ++;
    else if (snake->direction == DOWN) snake->body[0].x --;
    else if (snake->direction == LEFT) snake->body[0].y ++;
    else if (snake->direction == RIGHT) snake->body[0].y --;
    return overlap_check(snake);
}



int8_t overlap_check(Snake *snake) {
    for (int i=1; i<10; i++) {
        if (snake->body[i].x == snake->body[0].x && snake->body[i].y == snake->body[0].y) return -1;
    }
    return 0;
}


void random_food(Coord *food) {
    food->x = rand() % 8;
    food->y = rand() % 8;
}


void set_screen(Coord *food, Snake *snake){
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {   
            if (food->x == i && food->y == j)
            {
                    char row = virtual_screen[i];
                    row = 1 << j;
                    virtual_screen[i] |= row; 
            }

            for (int k=0; k<10; k++)
            {
                if (snake->body[k].x == i && snake->body[k].y == j)
                {
                    char row = virtual_screen[i];
                    row = 1 << j;
                    virtual_screen[i] |= row; 
                }
            }
        }
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
