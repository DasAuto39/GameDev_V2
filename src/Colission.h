#ifndef COLISSION_H
#define COLISSION_H


#include "SDL.h"

class Collision
{
public:
    static bool checkCollision(const SDL_Rect& a, const SDL_Rect& b);
};


#endif // COLLISION_H
