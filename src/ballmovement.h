#ifndef BALLMOVEMENT_H
#define BALLMOVEMENT_H

#include "Ballz.h"
#include "SDL.h"

class ballmovement : public Ballz {
public:
    ballmovement(float p_x, float p_y, SDL_Texture* p_tex);
    void updateLtoR();
    void updateRtoL();
};

#endif // BALLMOVEMENT_H
