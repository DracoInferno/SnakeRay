#include "SnakeRay_Snake.h"

Snake_st* Snake_ctor(Rectangle size_n_pos, Color h_color, Color b_color)
{
    Snake_st *me = MemAlloc(sizeof(*me));
    if(!me){
        TraceLog(LOG_FATAL, "Error allocating Snake_st object!");
        exit(1);
    }

    // Always to the top
    me->direction = (Vector2){0.0, -1.0};
    me->head = size_n_pos;
    me->head_color = h_color;
    me->body_color = b_color;
    // No body at creation
    me->body = NULL;
    me->body_size = 0;
    me->max_size = 0;

    return me;
}

void Snake_dtor(Snake_st *me)
{
    assert(me);
    if(me->body)
        MemFree(me->body);
    me->body = NULL; 
    MemFree(me);
}

void Snake_step(Snake_st *me)
{
    assert(me);

    if(me->body_size > 0){
        // Step body position from end to second to last before head
        for(size_t i=0 ; i<me->body_size-1 ; i++){
            me->body[i] = me->body[i+1];
        }
        // Step the closest to head (which is the last in the array)
        if(me->body)
            me->body[me->body_size-1] = me->head;
    }

    // Step head
    me->head.x += me->direction.x * me->head.width;
    me->head.y += me->direction.y * me->head.width;
}

void Snake_turn(Snake_st *me, Vector2 new_direction)
{
    assert(me);

    // Forbids 180° turn
    if((new_direction.x * -1.0f) != me->direction.x &&
       (new_direction.y * -1.0f) != me->direction.y){
        me->direction = new_direction;
    }
}

void Snake_grow(Snake_st *me)
{
    assert(me);

    // Grow body array
    if(me->body_size >= me->max_size){
        me->max_size += 30;
        me->body = MemRealloc(me->body, sizeof(*(me->body)) * me->max_size);
        if(!me->body){
            TraceLog(LOG_FATAL, "Error allocating Snake_st body!");
            exit(1);
        }
    }

    // Add new body segment at the end
    me->body[me->body_size++] = me->head;

    // Step head
    me->head.x += me->direction.x * me->head.width;
    me->head.y += me->direction.y * me->head.width;
}

void Snake_draw(Snake_st *me)
{
    assert(me);

    // Draw head
    DrawRectangleRec(me->head, me->head_color);
    // Draw body
    for(size_t i=0 ; i<me->body_size ; i++){
        DrawRectangleRec(me->body[i], me->body_color);
    }
}

bool Snake_bite_itself(Snake_st *me)
{
    for(size_t i=0 ; i<me->body_size ; i++){
        if(me->head.x == me->body[i].x && me->head.y == me->body[i].y)
            return true;
    }

    return false;
}

bool Snake_is_on_snake(Snake_st *me, Vector2 fruit)
{
    if(me->head.x == fruit.x && me->head.y == fruit.y)
        return true;

    for(size_t i=0 ; i<me->body_size ; i++){
        if(me->body[i].x == fruit.x && me->body[i].y == fruit.y)
            return true;
    }

    return false;
}

Vector2 Snake_get_head_pos(Snake_st *me)
{
    return (Vector2){me->head.x, me->head.y};
}