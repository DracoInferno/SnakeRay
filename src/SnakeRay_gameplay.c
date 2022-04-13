#include "SnakeRay.h"

static bool inited = false;
static Snake_st *snake = NULL;
static Vector2 fruit = {0.0, 0.0};
// static const float UNIT = 15.0;
// Margins computed from screen dimensions, greater or equal than MIN_MARGIN
static float real_w_margin = 0;
static float real_h_margin = 0;
static int row_nb = 0;
static int col_nb = 0;
// "Physics board"
static Rectangle board = {0};
// Board for drawing, taking boder wifth into account
static Rectangle drawing_board = {0};
static uint32_t score = 0;
static sds score_str;
static double time_step_s;
static double last_time_s;

void screen_gameplay_init(void)
{
	ClearWindowState(FLAG_WINDOW_RESIZABLE);

    // Setup board
    row_nb = floorf((GetScreenWidth() - 2*MIN_MARGIN)/UNIT);
    board.width = row_nb*UNIT;
    real_w_margin = (GetScreenWidth() - board.width)/2.0;
    board.x = real_w_margin;
    col_nb = floorf((GetScreenHeight() - 2*MIN_MARGIN)/UNIT);
    board.height = col_nb*UNIT;
    real_h_margin = (GetScreenHeight() - board.height)/2.0;
    board.y = real_h_margin;

    drawing_board.x = board.x - BOARD_LINE_W;
    drawing_board.y = board.y - BOARD_LINE_W;
    drawing_board.width = board.width + 2*BOARD_LINE_W;
    drawing_board.height = board.height + 2*BOARD_LINE_W;

    // Spawn Snake in the board center
    snake = Snake_ctor(
        (Rectangle){
            board.x + UNIT*floorf(row_nb/2),
            board.y + UNIT*floorf(col_nb/2),
            UNIT, UNIT
        },
        RED, RED
    );
    make_valid_fruit();
    score = 0;
    time_step_s = compute_time_step(score);
    score_str = sdsnew("Score: 0");
    last_time_s = GetTime();
    inited = true;
}

void screen_gameplay_update(void)
{
    double elapsed_s = GetTime() - last_time_s;

    if(!inited)
        screen_gameplay_init();
	
    if(IsKeyPressed(KEY_UP)){
        Snake_turn(snake, (Vector2){0, -1});
    }
    if(IsKeyPressed(KEY_DOWN)){
        Snake_turn(snake, (Vector2){0, 1});
    }
    if(IsKeyPressed(KEY_LEFT)){
        Snake_turn(snake, (Vector2){-1, 0});
    }
    if(IsKeyPressed(KEY_RIGHT)){
        Snake_turn(snake, (Vector2){1, 0});
    }

    if(elapsed_s >= time_step_s){
        if(is_snake_on_fruit()){
            Snake_grow(snake);
            score++;
            score_str = sdscatprintf(sdsempty(), "Score: %d", score);
            make_valid_fruit();
            time_step_s = compute_time_step(score);
        }
        else{
            Snake_step(snake);
            if(Snake_bite_itself(snake) || Snake_is_oob(snake, board))
                g_ctx.next_screen = GAMEOVER;

        }
        last_time_s = GetTime();
    }

    if(g_ctx.next_screen != GAMEPLAY)
        screen_gameplay_deinit();
}
void screen_gameplay_draw(void)
{
    if(inited){
        DrawRectangleLinesEx(drawing_board, 5, BLACK);
        Snake_draw(snake);
        DrawRectangle(fruit.x, fruit.y, UNIT, UNIT, PURPLE);
        DrawText(score_str, 50, 0, 20, BLACK);
    }
}
void screen_gameplay_deinit(void)
{
    if(inited){
        Snake_dtor(snake);
        inited = false;
    }
    sdsfree(score_str);
	SetWindowState(FLAG_WINDOW_RESIZABLE);
}

void make_valid_fruit(void)
{
    srand(time(NULL));
    do{
        fruit.x = GetRandomValue(0, row_nb-1)*UNIT + real_w_margin;
        fruit.y = GetRandomValue(0, col_nb-1)*UNIT + real_h_margin;
    }while(Snake_is_on_snake(snake, fruit));
}

bool is_snake_on_fruit()
{
    Vector2 snake_head = Snake_get_head_pos(snake);
    return (fruit.x == snake_head.x && fruit.y == snake_head.y);
}