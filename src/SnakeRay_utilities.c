#include "SnakeRay.h"

void rng_vec2(Vector2 *dest, Vector2 bounds)
{
    assert(dest);

    // srand(time(NULL));

    float x = floor((bounds.x * rand())/RAND_MAX);
    float y = floor((bounds.y * rand())/RAND_MAX);

    dest->x = x;
    dest->y = y;
}