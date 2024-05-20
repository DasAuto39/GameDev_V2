#ifndef MYCHARACTER_H
#define MYCHARACTER_H


#include "SDL.h"
#include "SDL_image.h"




class MyCharacter
{
public:
    MyCharacter(float p_x, float p_y, SDL_Texture* p_tex);
	float getXpos() ;
	float getYpos() ;
	void handleevent(SDL_Event& event);
	void checkcolission() ;
	SDL_Texture* getTex() ;
	SDL_Rect getCurrentFrame() ;
private:
	float xpos, ypos;
    int life;
    int xspeed, yspeed;
	SDL_Rect currentFrame;
	SDL_Texture* tex;
};
#endif // MYCHARACTER_H
