#include "MyCharacter.h"

MyCharacter::MyCharacter(float p_x, float p_y, SDL_Texture* p_tex)
:xpos(p_x), ypos(p_y), tex(p_tex)
{
    currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 32;
	currentFrame.h = 32;
}

float MyCharacter::getXpos()
{
    return xpos;
}

float MyCharacter::getYpos()
{
    return ypos;
}

void MyCharacter::handleevent(SDL_Event& event)
{

}

SDL_Texture* MyCharacter::getTex()
{
    return tex;
}

SDL_Rect MyCharacter::getCurrentFrame()
{
    return currentFrame;
}
