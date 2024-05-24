#ifndef MYCHARACTER_H
#define MYCHARACTER_H

#include "SDL.h"
#include "SDL_image.h"
#include "Entity.h"
#include "Collision.h"
#include "ballmovement.h"
#include "Ballz.h"

class MyCharacter
{
public:
    MyCharacter(float p_x, float p_y, SDL_Texture* p_tex);
    void handleEvent(SDL_Event& event);
    void update(Entity crates[], int numCrates);
    void checkCollisionCrateAndMC(Entity crates[], int numCrates);
    void checkCollisionWithBalls(ballmovement ball[],int numBall);
    void respawn();
    SDL_Texture* getTex();
    SDL_Rect* rtunSRCMC();
    SDL_Rect* rtunDSTMC();
    SDL_Rect getCurrentFrame();
    const char* getLifeMC();
    int getLifeMCINT();

private :
    Uint32 gracePeriodStart;
    static const Uint32 gracePeriodDuration = 3000; // 3 seconds
    SDL_Rect srcMC, dstMC;
    float xposMC, yposMC;
    int lifeMC = 5;
    int xspeedMC, yspeedMC;
    SDL_Rect currentFrame;
    SDL_Texture* tex;
};

#endif // MYCHARACTER_H
