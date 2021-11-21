#ifndef SNAKERAY_H
#define SNAKERAY_H

#include <stdlib.h>
#include <stdio.h>
#include <raylib.h>
#include "RayLibText.h"

#define WINDOW_W 800
#define WINDOW_H 450

typedef enum GameScreen{
    TITLE,
    MENU,
    GAMEPLAY,
    ENDING
}GameScreen;

// Main game loop
void SnakeRay(int argc, char *argv[]);

#endif //SNAKERAY_H
