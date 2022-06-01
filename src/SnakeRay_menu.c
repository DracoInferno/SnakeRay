#include "SnakeRay.h"

#define TITLE_TXT "MENU"

static bool inited = false;
static Vector2 title_pos = {0};
static float title_w = 0;

void screen_menu_init(void)
{
    title_w = MeasureText(TITLE_TXT, TITLE_SIZE);
    title_pos.x = obj_pos_screen_center(title_w);
    title_pos.y = 15;
    inited = true;
}
void screen_menu_update(void)
{
    if(!inited)
        screen_menu_init();
	
    if(IsWindowResized())
        screen_menu_init();

    if(g_ctx.next_screen != MENU)
        screen_menu_deinit();
}
void screen_menu_draw(void)
{
    DrawText(TITLE_TXT, title_pos.x, title_pos.y, TITLE_SIZE, RED);
    // DrawRectangle((GetScreenWidth()/2)*(1 + sin(GetTime())), 200, 20, 20, GREEN);
    if (GuiButton((Rectangle){25.0f, 25.0f, 50.0f, 20.0f}, "#05#PLAY")) {
        g_ctx.next_screen = GAMEPLAY;
    }
    if(GuiTextBoxMulti((Rectangle){ 320, 25, 225, 140 }, "TOTO foo truc", 256, false))
        printf("TextBoxMulti click");
}
void screen_menu_deinit(void)
{
    if(inited){
        inited = false;
    }
}