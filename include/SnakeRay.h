#ifndef SNAKERAY_H
#define SNAKERAY_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <raylib.h>
#include "RayLibText.h"
#include "SnakeRay_Snake.h"

#define WINDOW_W 480
#define WINDOW_H 360

typedef enum GameScreen_st{
    NONE,
    TITLE,
    MENU,
    GAMEPLAY,
    ENDING
}GameScreen_st;

typedef enum Gameplay_st{
    GAMEPLAY_INIT,
    GAMEPLAY_PLAY,
    GAMEPLAY_DEINIT
}Gameplay_st;

typedef struct GlobalContext_st{
	char game_title[16];
	bool show_fps;
	Font font;
	int h1_size;
	int h1_spacing;
	GameScreen_st current_screen;
	GameScreen_st next_screen;
	Gameplay_st gameplay_state;
}GlobalContext_st;

extern GlobalContext_st g_ctx;

// MAIN GAME LOOP
// -------------------------------------------------------------------------
void SnakeRay(int argc, char *argv[]);

// < TITLE > SCREEN
// -------------------------------------------------------------------------
void screen_title_init(void);
void screen_title_update(void);
void screen_title_draw(void);
void screen_title_deinit(void);

// < MENU > SCREEN
// -------------------------------------------------------------------------
void screen_menu_init(void);
void screen_menu_update(void);
void screen_menu_draw(void);
void screen_menu_deinit(void);

// < GAMEPLAY > SCREEN
// -------------------------------------------------------------------------
void screen_gameplay_init(void);
void screen_gameplay_update(void);
void screen_gameplay_draw(void);
void screen_gameplay_deinit(void);

bool is_fruit_valid(void);

// < ENDING > SCREEN
// -------------------------------------------------------------------------
void screen_ending_init(void);
void screen_ending_update(void);
void screen_ending_draw(void);
void screen_ending_deinit(void);

// Utilities
// -------------------------------------------------------------------------
void rng_vec2(Vector2 *dest, Vector2 bounds);

#endif //SNAKERAY_H