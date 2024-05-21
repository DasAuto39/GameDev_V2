#ifndef MYCHARACTER_H
#define MYCHARACTER_H

#include "SDL.h"
#include "SDL_image.h"
#include "Entity.h"

class MyCharacter
{
public:
    MyCharacter(float p_x, float p_y, SDL_Texture* p_tex);
    float getXpos();
    float getYpos();
    void handleEvent(SDL_Event& event);
    void update();
    void checkCollision(Entity entities[], int size);
    SDL_Texture* getTex();
    SDL_Rect* rtunSRCMC();
    SDL_Rect* rtunDSTMC();
    SDL_Rect getCurrentFrame();
private:
    SDL_Rect srcMC, dstMC;
    float xpos, ypos;
    int life;
    int xspeed, yspeed;
    SDL_Rect currentFrame;
    SDL_Texture* tex;
};

#endif // MYCHARACTER_H
