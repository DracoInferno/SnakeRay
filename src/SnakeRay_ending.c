#include "SnakeRay.h"

static bool inited = false;

void screen_ending_init(void)
{
    inited = true;
}
void screen_ending_update(void)
{
    if(!inited)
        screen_ending_init();
	
    if(IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
        g_ctx.next_screen = ENDING;

    if(g_ctx.next_screen != ENDING)
        screen_ending_deinit();
}
void screen_ending_draw(void)
{
    DrawText("This is ending screen", 100, 100, 20, BLACK);
}
void screen_ending_deinit(void)
{
    if(inited){
        inited = false;
    }
}