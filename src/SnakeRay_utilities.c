#include "SnakeRay.h"

void rng_vec2(Vector2 *dest, Rectangle bounds)
{
    assert(dest);

    // srand(time(NULL));

    float x = GetRandomValue(bounds.x, bounds.x + bounds.width);
    float y = GetRandomValue(bounds.y, bounds.y + bounds.height);

    dest->x = x;
    dest->y = y;
}

double compute_time_step(uint32_t score)
{
    return T0 * expf(-0.01*(double)score);
}

int obj_pos_screen_center(float length)
{
    return (GetScreenWidth() - length)/2;
}