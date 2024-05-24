#ifndef BALLMOVEMENT_H
#define BALLMOVEMENT_H

#include "Ballz.h"
#include "SDL.h"
#include "Collision.h"
#include "Entity.h"

class ballmovement : public Ballz {
public:
    ballmovement(float p_x, float p_y, SDL_Texture* p_tex);
    void updateLtoR(Entity crates[], int numCrate);
    void updateRtoL(Entity crates[], int numCrate);
    SDL_Rect GetNotptrDSTBMB();
    void checkCollisionLtoR(Entity crates[], int numCrates);
    void checkCollisionRtoL(Entity crates[], int numCrates);
};

#endif // BALLMOVEMENT_H
