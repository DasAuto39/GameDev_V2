#ifndef BALLZ_H
#define BALLZ_H
#include "SDL.h"
#include "SDL_image.h"

class Ballz
{
    public:
        Ballz();
        Ballz(float p_x, float p_y, SDL_Texture* p_tex);
        SDL_Rect* rtunSRCB();
        SDL_Rect* rtunDSTB();
        SDL_Rect GetNotDSTptrB();
        SDL_Texture* getTexB();
        void updateLtoR();
        SDL_Rect getCurrentFrameB();
      private:
        SDL_Rect srcB, dstB;
        float xposB, yposB;
        int xspeedB, yspeedB;
        SDL_Rect currentFrameB;
        SDL_Texture* texB;
};

#endif // BALLZ_H
