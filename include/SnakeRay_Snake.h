#ifndef SNAKERAY_SNAKE_H
#define SNAKERAY_SNAKE_H

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <raylib.h>

typedef struct Snake{
    Vector2 direction;
    Vector2 head;
    size_t width;
    Vector2 *body;
    size_t body_size;
    size_t max_size;
    Color head_color;
    Color body_color;
}Snake_st;

Snake_st* Snake_ctor(Vector2 pos, size_t elem_width, Color h_color, Color b_color);
void Snake_dtor(Snake_st *me);

void Snake_step(Snake_st *me);
void Snake_turn(Snake_st *me, Vector2 new_direction);
void Snake_grow(Snake_st *me);
void Snake_draw(Snake_st *me);

Vector2 Snake_get_head_pos(Snake_st *me);

#endif //SNAKERAY_SNAKE_H
