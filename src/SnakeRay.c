#include "SnakeRay.h"

GlobalContext_st g_ctx;

void SnakeRay(int argc, char *argv[])
{
	// INITIALIZATION
	// -----------------------------------------------------------------------------------
	InitWindow(WINDOW_W, WINDOW_H, "SnakeRay");
	SetWindowState(FLAG_WINDOW_RESIZABLE);
	SetWindowMinSize(480, 360);
	SetTargetFPS(60);
    g_ctx.current_screen = NONE;
    g_ctx.next_screen = TITLE;
	g_ctx.gameplay_state = GAMEPLAY_INIT;
	g_ctx.show_fps = true;
	g_ctx.font = GetFontDefault();
	g_ctx.h1_size = 20;
	g_ctx.h1_spacing = 5;

	// GAME LOOP
	// -----------------------------------------------------------------------------------
	while (!WindowShouldClose())
	{
        g_ctx.current_screen = g_ctx.next_screen;

		// GAME LOGIC
		// -------------------------------------------------------------------------------
		if(IsKeyPressed(KEY_TAB))
			g_ctx.show_fps ^= 1;

		switch(g_ctx.current_screen)
		{
			case TITLE: screen_title_update(); break;
			case MENU: screen_menu_update(); break;
			case GAMEPLAY: screen_gameplay_update(); break;
			case GAMEOVER: screen_gameover_update(); break;
			default: break;
	    }

        // RENDERRING
        // -------------------------------------------------------------------------------
		BeginDrawing();
		{
			ClearBackground(RAYWHITE);
            
			switch(g_ctx.current_screen)
			{
				case TITLE: screen_title_draw(); break;
				case MENU: screen_menu_draw(); break;
				case GAMEPLAY: screen_gameplay_draw(); break;
				case GAMEOVER: screen_gameover_draw(); break;
				default: break;
			}

			if(g_ctx.show_fps)
				DrawFPS(5, 0);
		}
		EndDrawing();
    }

    // DE INITIALIZATION
    // -----------------------------------------------------------------------------------
    screen_title_deinit();
    screen_menu_deinit();
    screen_gameplay_deinit();
    screen_gameover_deinit();

    CloseWindow();
}
