#include "SnakeRay_Snake.h"

Snake_st* Snake_ctor(Vector2 pos, size_t elem_width, Color h_color, Color b_color)
{
    Snake_st *me = MemAlloc(sizeof(*me));
    if(!me){
        TraceLog(LOG_FATAL, "Error allocating Snake_st object!");
        exit(1);
    }

    me->width = elem_width;
    // Always to the top
    me->direction = (Vector2){0.0, -1.0};
    me->head = pos;
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

    // Update body position from end to [1]
    //for(size_t i=me->body_size-1 ; i>0 ; i--){
    //    me->body[i] = me->body[i-1];
    //}
    // Update first body item
    //if(me->body)
    //    me->body[0] = me->head;

    // Update head
    me->head.x += me->direction.x * me->width;
    me->head.y += me->direction.y * me->width;
}

void Snake_turn(Snake_st *me, Vector2 new_direction)
{
    assert(me);

    // Forbids 180° turn
    if((new_direction.x * -1.0) != me->direction.x &&
       (new_direction.y * -1.0) != me->direction.y){
        me->direction = new_direction;
    }
}

void Snake_grow(Snake_st *me)
{
    assert(me);

    if(me->body_size >= me->max_size){
        me->max_size += 10;
        me->body = MemRealloc(me->body, me->max_size);
        if(!me->body){
            TraceLog(LOG_FATAL, "Error allocating Snake_st body!");
            exit(1);
        }
    }


// RESUME

}

void Snake_draw(Snake_st *me)
{
    assert(me);

    DrawRectangle(me->head.x, me->head.y, me->width, me->width, me->head_color);
    for(size_t i=0 ; i<me->body_size ; i++){
        DrawRectangle(me->body[i].x, me->body[i].y, me->width, me->width, me->body_color);
    }
}