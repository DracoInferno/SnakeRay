#include "SnakeRay.h"

static bool inited = false;
static Snake_st *snake = NULL;
static Vector2 fruit = {0.0, 0.0};
static double time_step_s = 0.250;
static double last_time_s = 0.0;

void screen_gameplay_init(void)
{
	ClearWindowState(FLAG_WINDOW_RESIZABLE);

    snake = Snake_ctor((Vector2){GetScreenWidth()/2, GetScreenHeight()/2}, 10, RED, BLUE);
    make_valid_fruit();

    last_time_s = GetTime();
    inited = true;
}

void screen_gameplay_update(void)
{
    double elapsed_s = GetTime() - last_time_s;

    if(!inited)
        screen_gameplay_init();
	
    if(IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
        g_ctx.next_screen = ENDING;
    
    if(IsKeyPressed(KEY_UP)){
        Snake_turn(snake, (Vector2){0, -1});
    }
    else if(IsKeyPressed(KEY_DOWN)){
        Snake_turn(snake, (Vector2){0, 1});
    }
    else if(IsKeyPressed(KEY_LEFT)){
        Snake_turn(snake, (Vector2){-1, 0});
    }
    else if(IsKeyPressed(KEY_RIGHT)){
        Snake_turn(snake, (Vector2){1, 0});
    }

    if(elapsed_s >= time_step_s){
        if(is_snake_on_fruit()){
            Snake_grow(snake);
            make_valid_fruit();
        }
        else
            Snake_step(snake);

        last_time_s = GetTime();
    }

    if(g_ctx.next_screen != GAMEPLAY)
        screen_gameplay_deinit();
}
void screen_gameplay_draw(void)
{
    Snake_draw(snake);
    DrawRectangle(fruit.x, fruit.y, 10, 10, PURPLE);
}
void screen_gameplay_deinit(void)
{
    if(inited){
        Snake_dtor(snake);
        inited = false;
    }
	SetWindowState(FLAG_WINDOW_RESIZABLE);
}

void make_valid_fruit(void)
{
    srand(time(NULL));
    do{
        rng_vec2(&fruit, (Vector2){GetScreenWidth(), GetScreenHeight()});
    }while(Snake_is_on_snake(snake, fruit));
}

bool is_snake_on_fruit()
{
    Vector2 snake_head = Snake_get_head_pos(snake);
    return (fruit.x == snake_head.x && fruit.y == snake_head.y);
}