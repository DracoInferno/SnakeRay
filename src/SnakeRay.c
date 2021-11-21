#include <stdlib.h>
#include <stdio.h>
#include <raylib.h>
#include "SnakeRay.h"

void SnakeRay(int argc, char *argv[])
{
    // INITIALIZATION
    // -----------------------------------------------------------------------------------
    InitWindow(800, 450, "SnakeRay");
    SetTargetFPS(60);

    GameScreen current_screen = LOGO;
    bool show_fps = true;

    // GAME LOOP
    // -----------------------------------------------------------------------------------
    while (!WindowShouldClose())
    {
	// GAME LOGIC
	// -------------------------------------------------------------------------------
	if(IsKeyPressed(KEY_TAB))
	    show_fps = !show_fps;
	switch(current_screen)
	{
	    case LOGO:
	    {

	    }break;

	    case TITLE:
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
		case LOGO:
		{
		    DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
		}break;

		case TITLE:
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
        
	EndDrawing();
    }

    // DE INITIALIZATION
    // -----------------------------------------------------------------------------------
    CloseWindow();
}
