#ifndef BALLMOVEMENT_H
#define BALLMOVEMENT_H


#include "SDL.h"

class ballmovement {
public:
    ballmovement(float p_x, float p_y);
    void updateLtoR();
    void updateRtoL();

protected:
    float xposB, yposB;
    int xspeedB, yspeedB;
};
#endif // BALLMOVEMENT_H
