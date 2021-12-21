#ifndef SNAKERAY_H
#define SNAKERAY_H

#include <stdlib.h>
#include <stdio.h>
#include <raylib.h>
#include "RayLibText.h"

#define WINDOW_W 800
#define WINDOW_H 450

typedef enum GameScreen_st{
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

// Main game
void SnakeRay(int argc, char *argv[]);

#endif //SNAKERAY_H
