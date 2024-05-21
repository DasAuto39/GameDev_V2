#include "MyCharacter.h"
#include "iostream"

MyCharacter::MyCharacter(float p_x, float p_y, SDL_Texture* p_tex)
    : xpos(p_x), ypos(p_y), tex(p_tex), xspeed(0), yspeed(0), life(3)
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

void MyCharacter::handleEvent(SDL_Event& event)
{
    if (event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            yspeed = -1;
            break;
        case SDLK_DOWN:
            yspeed = 1;
            break;
        case SDLK_LEFT:
            xspeed = -1;
            break;
        case SDLK_RIGHT:
            xspeed = 1;
            break;
        }
    }
    else if (event.type == SDL_KEYUP)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
        case SDLK_DOWN:
            yspeed = 0;
            break;
        case SDLK_LEFT:
        case SDLK_RIGHT:
            xspeed = 0;
            break;
        }
    }
}

void MyCharacter::update()
{
    xpos += xspeed;
    ypos += yspeed;

    if (xpos < 0)
        {
            xspeed = 0;
            xpos = 0;
        }
    if (xpos > 670)
        {
            xspeed = 0;
            xpos = 670;
        }
    if (ypos < -30)
        {
            yspeed = 0;
            ypos = -30;
        }
    if (ypos > 576)
        {
            yspeed = 0;
            ypos = 576;
        }
}

SDL_Rect* MyCharacter::rtunDSTMC()
{
    dstMC.x = xpos;
    dstMC.y = ypos;
    dstMC.w = currentFrame.w * 2;
    dstMC.h = currentFrame.h * 2;

    return &dstMC;
}

SDL_Rect* MyCharacter::rtunSRCMC()
{
    srcMC.x = currentFrame.x;
    srcMC.y = currentFrame.y;
    srcMC.w = currentFrame.w;
    srcMC.h = currentFrame.h;

    return &srcMC;
}


SDL_Texture* MyCharacter::getTex()
{
    return tex;
}

SDL_Rect MyCharacter::getCurrentFrame()
{
    return currentFrame;
}
