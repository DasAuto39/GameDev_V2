#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "RenderWindow.h"
#include "SDL.h"
#include "SDL_image.h"
#include "MyCharacter.h"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
	:window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}


SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);

	if (texture == NULL)
		std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
	return texture;
}




void RenderWindow::render(Entity& p_entity)
{
	SDL_RenderCopy(renderer, p_entity.getTex(), p_entity.rtunSRCE(), p_entity.rtunDSTE());
}

void RenderWindow::render(MyCharacter& p_MC)
{
	SDL_RenderCopy(renderer, p_MC.getTex(), p_MC.rtunSRCMC(), p_MC.rtunDSTMC());
}


void RenderWindow::render(SDL_Texture* texture, SDL_Rect src, SDL_Rect dst)  // Ensure this is defined
{
    SDL_RenderCopy(renderer, texture, &src, &dst);
}
void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}


void RenderWindow::cleanUp()
{
	SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
}
