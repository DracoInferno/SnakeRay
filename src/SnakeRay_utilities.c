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
    return T0 * exp(-0.01*(double)score);
}