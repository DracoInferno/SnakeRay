#include "SnakeRay.h"

static bool inited = false;
static const char *title = "Welcome to SnakeRay, a snake game using c RayLib.\nPress ENTER or click.";
static Vector2 title_pos = {0};

void screen_title_init(void)
{
	title_pos = TextPosCenter(&g_ctx.font,title, g_ctx.h1_size, g_ctx.h1_spacing, GetScreenWidth(), GetScreenHeight());
    
    inited = true;
}

void screen_title_update(void)
{
    if(!inited)
        screen_title_init();
	
    if(IsWindowResized()){
		title_pos = TextPosCenter(&g_ctx.font,title, g_ctx.h1_size, g_ctx.h1_spacing, GetScreenWidth(), GetScreenHeight());
	}
    if(IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
        g_ctx.next_screen = MENU;
    
    if(g_ctx.next_screen != TITLE)
        screen_title_deinit();
}

void screen_title_draw(void)
{
	DrawTextEx(g_ctx.font, title, title_pos, g_ctx.h1_size, g_ctx.h1_spacing, DARKPURPLE);
}

void screen_title_deinit(void)
{
    if(inited){
        inited = false;
    }
}