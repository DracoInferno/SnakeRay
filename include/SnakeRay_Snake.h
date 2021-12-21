#ifndef SNAKERAY_SNAKE_H
#define SNAKERAY_SNAKE_H

#include <raylib.h>

typedef struct Snake{
    Vector2 direction,
    Vector2 head,
    Vector2 *body,
    Color head_color,
    Color *body_color
}Snake;

Snake* Snake_ctor(Vector2 pos, uint32_t max_size, Color head, Color body);

#endif //SNAKERAY_SNAKE_H
