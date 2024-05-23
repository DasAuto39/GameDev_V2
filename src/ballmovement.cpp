#include "ballmovement.h"


ballmovement::ballmovement(float p_x, float p_y, int p_xspeed, int p_yspeed)
    : xpos(p_x), ypos(p_y), xspeed(p_xspeed), yspeed(p_yspeed)
{}

void ballmovement::updateLtoR() {
    xpos += xspeed;
    ypos += yspeed;

    // Bounce off the edges of the screen (example values, adjust as necessary)
    if (xpos < 0 ) {
        xspeed = +xspeed;
    }
    if (xpos > 0){
        xspeed = +xspeed;
    }
}

