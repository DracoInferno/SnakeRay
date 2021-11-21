#ifndef RAYLIBTEXT_H
#define RAYLIBTEXT_H

#include <raylib.h>

//Return x,y pos for the text to be centered
Vector2 TextPosCenter(Font *font, const char *text, float font_size, float spacing, int window_w, int window_h);

#endif //RAYLIBTEXT_H
