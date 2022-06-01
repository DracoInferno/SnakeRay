#include "SnakeRay.h"

#define TITLE_TXT "GAMEOVER"

static bool inited = false;
static Vector2 title_pos = {0};
static float title_w = 0;

void screen_gameover_init(void)
{
    title_w = MeasureText(TITLE_TXT, TITLE_SIZE);
    title_pos.x = obj_pos_screen_center(title_w);
    title_pos.y = 15;
    inited = true;
}
void screen_gameover_update(void)
{
    if(!inited)
        screen_gameover_init();
	
    if(IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
        g_ctx.next_screen = MENU;

    if(g_ctx.next_screen != GAMEOVER)
        screen_gameover_deinit();
}
void screen_gameover_draw(void)
{
    DrawText(TITLE_TXT, title_pos.x, title_pos.y, TITLE_SIZE, BLACK);
}
void screen_gameover_deinit(void)
{
    if(inited){
        inited = false;
    }
}