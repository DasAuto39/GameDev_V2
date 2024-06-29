#include "MyCharacter.h"
#include "Entity.h"
#include "ballmovement.h"
#include "Ballz.h"
#include "iostream"
#include <string>



MyCharacter::MyCharacter(float p_x, float p_y, SDL_Texture* p_tex)
    : xposMC(p_x), yposMC(p_y), tex(p_tex), xspeedMC(0), yspeedMC(0)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;
}

void MyCharacter::handleEvent(SDL_Event& event)
{
    if (event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            yspeedMC = -1;
            break;
        case SDLK_DOWN:
            yspeedMC = 1;
            break;
        case SDLK_LEFT:
            xspeedMC = -1;
            break;
        case SDLK_RIGHT:
            xspeedMC = 1;
            break;
        }
    }
    else if (event.type == SDL_KEYUP)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
        case SDLK_DOWN:
            yspeedMC = 0;
            break;
        case SDLK_LEFT:
        case SDLK_RIGHT:
            xspeedMC = 0;
            break;
        }
    }
}

void MyCharacter::update(Entity crates[], int numCrates)
{
    xposMC += xspeedMC;
    yposMC += yspeedMC;

    if (xposMC < 0)
        {
            xspeedMC = 0;
            xposMC = 0;
        }
    if (xposMC > 670)
        {
            xspeedMC = 0;
            xposMC = 670;
        }
    if (yposMC < -30)
        {
            yspeedMC = 0;
            yposMC = -30;
        }
    if (yposMC > 576)
        {
            yspeedMC = 0;
            yposMC = 576;
        }

    checkCollisionCrateAndMC(crates, numCrates);
}

void MyCharacter::checkCollisionCrateAndMC(Entity crates[], int numCrates)
{
    SDL_Rect MC = { static_cast<int>(xposMC), static_cast<int>(yposMC), currentFrame.w * 2, currentFrame.h * 2 };

    for (int i = 0; i < numCrates; i++)
    {
        if (Collision::checkCollision(MC, crates[i].GetNotptrDSTE()))
        {

            xposMC -= xspeedMC;
            yposMC -= yspeedMC;
            xspeedMC = 0;
            yspeedMC = 0;
            break;
        }
    }
}

void MyCharacter::checkCollisionWithBalls(ballmovement ball[],int numBall)
{
    if (SDL_GetTicks() - gracePeriodStart <= gracePeriodDuration) {
        return;
    }
    SDL_Rect MC = { static_cast<int>(xposMC), static_cast<int>(yposMC), currentFrame.w * 2, currentFrame.h * 2 };

    for (int i = 0; i < numBall; i++)
    {
        SDL_Rect ballRect = ball[i].GetNotptrDSTBMB();
        if (Collision::checkCollision(MC, ballRect))
        {
            std::cout << "Collision detected with ball " << i << std::endl; // Debugging
            lifeMC = lifeMC -1;
            respawn();

            break;
        }
    }
}

bool MyCharacter::checkCollisionWithFlask(Entity& flask)
{
    SDL_Rect MC = { static_cast<int>(xposMC), static_cast<int>(yposMC), currentFrame.w * 2, currentFrame.h * 2 };

    if (Collision::checkCollision(MC, flask.GetNotptrDSTE()))
    {
        std::cout << "Collision detected with flask" << std::endl; // Debugging
        return true;
    }
    return false;
}


void MyCharacter::respawn() {
    xposMC = 350;
    yposMC = 550;
    xspeedMC = 0;
    yspeedMC = 0;
    gracePeriodStart = SDL_GetTicks(); // Reset the grace period timer
}



SDL_Rect* MyCharacter::rtunDSTMC()
{
    dstMC.x = xposMC;
    dstMC.y = yposMC;
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

const char* MyCharacter::getLifeMC()
{
	std::string L = std::to_string(lifeMC);
	L =" Life " + L;
	return L.c_str();
}

const char* MyCharacter::getPointMC()
{
	std::string L = std::to_string(pointMC);
	L =" Point " + L;
	return L.c_str();
}

void MyCharacter::setLife(int rlife) {
    this->lifeMC = rlife;
}

void MyCharacter::setPoint(int rpoint)
{
    this->pointMC = rpoint;
}

int MyCharacter::getLifeMCINT()
{
    return lifeMC;
}

int MyCharacter::getPointMCINT()
{

    return pointMC;
}

float MyCharacter::getxpos()
{
    return xposMC;
}
float MyCharacter::getypos()
{

    return yposMC;
}
