#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "RenderWindow.h"
#include "Entity.h"
#include "Map.h"
#include "MyCharacter.h"

int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        std::cout << "SDL_Init has failed. SDL_ERROR: " << SDL_GetError() << std::endl;
        return 1;
    }

    if (!(IMG_Init(IMG_INIT_PNG)))
    {
        std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Initialize the window
    RenderWindow window("GAME v1.0", 700, 640);
    Map gameMap(&window);

    // Load the texture for the entities
    SDL_Texture* Batu = window.loadTexture("img_obj/1.png");
    SDL_Texture* crates = window.loadTexture("img_obj/crate.png");
    SDL_Texture* MC = window.loadTexture("img_obj/elf_f_idle_anim_f0.png");
    // Create an array of entities
    Entity entities[4] =      {Entity(-32, 100, Batu),
                              Entity(636, 100, Batu),
                              Entity(-32, 400, Batu),
                              Entity(636, 400, Batu)};

    Entity Crates[4] =
    {
        Entity(50,54,crates),
        Entity(344,30,crates),
        Entity(255,520,crates),
        Entity(200,400,crates)
    };

    MyCharacter Mine(350,570,MC);
    bool gameRunning = true;
    SDL_Event event;

    while (gameRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                gameRunning = false;
        }

        window.clear();
        gameMap.cldrawmap();

        // Render all entities
        for (int i = 0; i < 4; i++)
        {
            window.render(entities[i]);
        }
        for (int i = 0; i < 4; i++)
        {
            window.render(Crates[i]);
        }

        window.render(Mine);
        window.display();
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}
