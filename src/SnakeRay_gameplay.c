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
// Board for drawing, taking boder width into account
static Rectangle drawing_board = {0};
static Vector2 score_pos = {0};
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
    real_w_margin = (GetScreenWidth() - board.width)/2.0f;
    board.x = real_w_margin;
    col_nb = floorf((GetScreenHeight() - 2*MIN_MARGIN)/UNIT);
    board.height = col_nb*UNIT;
    real_h_margin = (GetScreenHeight() - board.height)/2.0f;
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

    // Score Management
    score = 0;
    score_str = sdsnew("Score: 0");
    score_pos.x = GetScreenWidth() - MeasureText(score_str, SCORE_SIZE) - 5;
    score_pos.y = 0;
    time_step_s = compute_time_step(score);

    last_time_s = GetTime();
    inited = true;
}

void screen_gameplay_update(void)
{
    double elapsed_s = GetTime() - last_time_s;
    static Vector2 direction = {0.0, -1.0};

    if(!inited)
        screen_gameplay_init();
	
    if(IsKeyPressed(KEY_UP)){
        direction = (Vector2){0.0, -1.0};
    }
    if(IsKeyPressed(KEY_DOWN)){
        direction = (Vector2){0.0, 1.0};
    }
    if(IsKeyPressed(KEY_LEFT)){
        direction = (Vector2){-1.0, 0.0};
    }
    if(IsKeyPressed(KEY_RIGHT)){
        direction = (Vector2){1.0, 0.0};
    }

    if(elapsed_s >= time_step_s){
        if(is_snake_on_fruit()){
            Snake_update(snake, direction, true);
            score++;
            score_str = sdscatprintf(sdsempty(), "Score: %d", score);
            score_pos.x = GetScreenWidth() - MeasureText(score_str, SCORE_SIZE) - 5;
            make_valid_fruit();
            time_step_s = compute_time_step(score);
        }
        else{
            Snake_update(snake, direction, false);
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
        DrawRectangle(fruit.x, fruit.y, UNIT, UNIT, PURPLE);
        Snake_draw(snake);
        DrawText(score_str, score_pos.x, score_pos.y, 20, BLACK);
    }
}
void screen_gameplay_deinit(void)
{
    if(inited){
        Snake_dtor(snake);
        sdsfree(score_str);
        inited = false;
    }
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