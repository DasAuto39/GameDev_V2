#include "ballmovement.h"

ballmovement::ballmovement(float p_x, float p_y, SDL_Texture* p_tex)
: Ballz(p_x, p_y, p_tex) {
    // xspeedB and yspeedB are already initialized in the Ballz constructor
}

void ballmovement::updateLtoR() {
    xposB += xspeedB; // Move the ball to the right

    if (xposB > 720) { // Check if the ball has gone off the screen (example value, adjust as needed)
        xposB = -getCurrentFrameB().w * 2; // Reset xposB to the left edge
    }
}

void ballmovement::updateRtoL() {
    xposB -= xspeedB; // Move the ball to the left

    if (xposB < -getCurrentFrameB().w * 2) { // Check if the ball has gone off the screen (example value, adjust as needed)
        xposB = 720; // Reset xposB to the right edge
    }
}
