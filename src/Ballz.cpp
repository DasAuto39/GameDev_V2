#include "Ballz.h"



Ballz::Ballz(float p_x, float p_y, SDL_Texture* p_tex)
:xposB(p_x), yposB(p_y), texB(p_tex)
{
	currentFrameB.x = 0;
	currentFrameB.y = 0;
	currentFrameB.w = 32;
	currentFrameB.h = 32;
}


SDL_Rect* Ballz::rtunSRCB()
{
    srcB.x = currentFrameB.x;
	srcB.y = currentFrameB.y;
	srcB.w = currentFrameB.w;
	srcB.h = currentFrameB.h;

    return &srcB;
}

SDL_Rect* Ballz::rtunDSTB()
{
    dstB.x = xposB;
	dstB.y = yposB ;
	dstB.w = currentFrameB.w * 2;
	dstB.h = currentFrameB.h * 2;

	return &dstB;
}

void Ballz::updateLtoR()
{
    xspeedB = 10;
    xposB += xspeedB; // Move the ball to the right

    if (xposB > 720) // Check if the ball has gone off the screen
    {
        xposB = 0; // Reset xposB to the left edge
    }
}


SDL_Rect Ballz::GetNotDSTptrB()
{

}

SDL_Texture* Ballz::getTexB()
{
	return texB;
}

SDL_Rect Ballz::getCurrentFrameB()
{

}
    //dtor
