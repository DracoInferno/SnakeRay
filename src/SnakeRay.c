#include "SnakeRay.h"

void SnakeRay(int argc, char *argv[])
{
    // INITIALIZATION
    // -----------------------------------------------------------------------------------
    InitWindow(WINDOW_W, WINDOW_H, "SnakeRay");
    SetWindowMinSize(WINDOW_W, WINDOW_H);
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    SetTargetFPS(60);

    GameScreen current_screen = TITLE;
    bool show_fps = true;
    Font font = GetFontDefault();
    const char *title_text = "Welcome to SnakeRay, a snake game using c RayLib.\nPress ENTER or click.";
    int title_text_font_size = 20;
    int title_text_spacing = 5;
    Vector2 title_text_pos = TextPosCenter(&font,title_text, title_text_font_size, title_text_spacing, WINDOW_W, WINDOW_H);

    // GAME LOOP
    // -----------------------------------------------------------------------------------
    while (!WindowShouldClose())
    {
	// GAME LOGIC
	// -------------------------------------------------------------------------------
	if(IsKeyPressed(KEY_TAB))
	    show_fps = !show_fps;
	if(IsWindowResized())
	{
	    title_text_pos = TextPosCenter(&font,title_text, title_text_font_size, title_text_spacing,GetScreenWidth(), GetScreenHeight());
	}
	switch(current_screen)
	{
	    case TITLE:
	    {
		if(IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
		    current_screen = MENU;
	    }break;

	    case MENU:
	    {

	    }break;

	    case GAMEPLAY:
	    {

	    }break;

	    case ENDING:
	    {

	    }break;
	    default:break;
	}

	// RENDERRING
	// -------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

	    if(show_fps)
		DrawFPS(5, 0);

	    switch(current_screen)
	    {
		case TITLE:
		{
		    DrawTextEx(font, title_text, title_text_pos, title_text_font_size, title_text_spacing, DARKPURPLE);
		}break;

		case MENU:
		{
		    DrawText("This is menu screen", 100, 100, 20, RED);
		}break;

		case GAMEPLAY:
		{

		}break;

		case ENDING:
		{

		}break;
		default:break;
	    }
        
	EndDrawing();
    }

    // DE INITIALIZATION
    // -----------------------------------------------------------------------------------
    CloseWindow();
}
