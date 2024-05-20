#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H



#include <SDL.h>
#include <SDL_image.h>
#include "Entity.h"


class MyCharacter;

class RenderWindow
{
public:
	RenderWindow(const char* p_title, int p_w, int p_h);
    SDL_Texture* loadTexture(const char* p_filePath);
	void render(Entity& p_entity);
    void render(MyCharacter& p_MyCharacter);
    void render(SDL_Texture* texture,SDL_Rect src, SDL_Rect dst);
	void display();
    void cleanUp();
    void clear();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};
#endif // RENDERWINDOW_H
