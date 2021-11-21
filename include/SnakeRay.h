#ifndef SNAKERAY_H
#define SNAKERAY_H

typedef enum GameScreen{
    LOGO,
    TITLE,
    GAMEPLAY,
    ENDING
}GameScreen;

// Main game loop
void SnakeRay(int argc, char *argv[]);

#endif //SNAKERAY_H
