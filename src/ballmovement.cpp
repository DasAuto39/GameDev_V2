#include "ballmovement.h"


ballmovement::ballmovement(float p_x, float p_y)
: xposB(p_x), yposB(p_y), xspeedB(2), yspeedB(0)
{}

void ballmovement::updateLtoR()
{

    xposB += xspeedB; // Move the ball to the right

    if (xposB > 720) // Check if the ball has gone off the screen
    {
        xposB = 30; // Reset xposB to the left edge
    }
}

void ballmovement::updateRtoL()
{
    xposB -= xspeedB; // Move the ball to the right

    if (xposB < -32) // Check if the ball has gone off the screen
    {
        xposB = 604; // Reset xposB to the left edge
    }
}
