#include "RayLibText.h"

Vector2 TextPosCenter(Font *font, const char *text, float font_size, float spacing, int window_w, int window_h)
{
    Vector2 result = {0};
    Vector2 text_size = MeasureTextEx(*font, text, font_size, spacing);

    result.x = (window_w - text_size.x)/2;
    result.y = (window_h - text_size.y)/2;

    return result;
}
