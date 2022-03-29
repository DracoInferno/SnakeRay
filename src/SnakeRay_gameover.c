#include "SnakeRay.h"

static bool inited = false;

void screen_gameover_init(void)
{
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
    DrawText("GAMEOVER", 100, 100, 20, BLACK);
}
void screen_gameover_deinit(void)
{
    if(inited){
        inited = false;
    }
}