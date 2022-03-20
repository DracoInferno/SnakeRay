#include "SnakeRay.h"

static bool inited = false;

void screen_menu_init(void)
{
    inited = true;
}
void screen_menu_update(void)
{
    if(!inited)
        screen_menu_init();
	
    if(IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
        g_ctx.next_screen = GAMEPLAY;
    
    if(g_ctx.next_screen != MENU)
        screen_menu_deinit();
}
void screen_menu_draw(void)
{
    DrawText("This is menu screen", 100, 100, 20, RED);
    DrawRectangle((GetScreenWidth()/2)*(1 + sin(GetTime())), 200, 20, 20, GREEN);
}
void screen_menu_deinit(void)
{
    if(inited){
        inited = false;
    }
}