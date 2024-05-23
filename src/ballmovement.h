#ifndef BALLMOVEMENT_H
#define BALLMOVEMENT_H


//class ballmovement
#include "SDL.h"

class ballmovement {
public:
    ballmovement(float p_x, float p_y, int p_xspeed, int p_yspeed);
    void updateLtoR();


protected:
    float xpos, ypos;
    int xspeed, yspeed;
};
#endif // BALLMOVEMENT_H
