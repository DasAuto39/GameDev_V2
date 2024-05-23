#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "RenderWindow.h"
#include "Entity.h"
#include "Map.h"
#include "MyCharacter.h"
#include "Ballz.h"



int main(int argc, char** argv)
{
    const int FPS = 60;
    const int frameDelay = 1000/FPS;

    Uint32 frameStart;
    int frameTime;

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
    SDL_Texture* ball = window.loadTexture("img_obj/tile000.png");

    //Ballz
    Ballz ballin =  Ballz(30,100,ball);


    // Create an array of entities
    Entity entities[4] = {
        Entity(-32, 100, Batu),
        Entity(636, 100, Batu),
        Entity(-32, 400, Batu),
        Entity(636, 400, Batu)
    };

    Entity Crates[8] = {
        Entity(250, 54, crates),
        Entity(344, 200, crates),
        Entity(255, 520, crates),
        Entity(200, 400, crates),
        Entity(400, 400, crates),
        Entity(450, 300, crates),
        Entity(500, 200, crates),
        Entity(500, 100, crates),
    };

    MyCharacter Mine(350, 500, MC);
    bool gameRunning = true;
    SDL_Event event;

    while (gameRunning)
    {
        frameStart = SDL_GetTicks();
        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay -frameTime);
        }

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                gameRunning = false;
                Mine.handleEvent(event);

        }

        Mine.update(Crates, 10);
        window.clear();
        gameMap.cldrawmap();

        // Render all entities
        for (int i = 0; i < 4; i++)
        {
            window.render(entities[i]);
        }
        for (int i = 0; i < 10; i++)
        {
            window.render(Crates[i]);
        }
        window.render(ballin);
        window.render(Mine);
        window.display();
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}
