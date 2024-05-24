#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

#include "RenderWindow.h"
#include "Entity.h"
#include "Map.h"
#include "MyCharacter.h"
#include "Ballz.h"
#include "ballmovement.h"

int main(int argc, char** argv)
{
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    if (TTF_Init() < 0) {
        std::cout << "TTF_Init has failed. Error: " << TTF_GetError() << std::endl;
        return 1;
    }

    if (SDL_Init(SDL_INIT_VIDEO) > 0) {
        std::cout << "SDL_Init has failed. SDL_ERROR: " << SDL_GetError() << std::endl;
        return 1;
    }

    if (!(IMG_Init(IMG_INIT_PNG))) {
        std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    RenderWindow window("GAME v1.0", 700, 640);
    Map gameMap(&window);

    SDL_Texture* Batu = window.loadTexture("img_obj/1.png");
    SDL_Texture* crates = window.loadTexture("img_obj/crate.png");
    SDL_Texture* MC = window.loadTexture("img_obj/elf_f_idle_anim_f0.png");
    SDL_Texture* ball = window.loadTexture("img_obj/tile000.png");
    TTF_Font* font16 = TTF_OpenFont("fonts/cocogoose.ttf", 16);
    SDL_Color white = { 255, 255, 255 };

    ballmovement ballLtoR[2] = {
        ballmovement(32, 100, ball),
        ballmovement(32, 300, ball)
    };
    ballmovement ballRtoL[2] = {
        ballmovement(604, 160, ball),
        ballmovement(604, 300, ball)
    };

    Entity entities[4] = {
        Entity(-32, 100, Batu),
        Entity(636, 160, Batu),
        Entity(-32, 300, Batu),
        Entity(636, 300, Batu)
    };

    Entity Crates[8] = {
        Entity(250, 54, crates),
        Entity(344, 260, crates),
        Entity(255, 520, crates),
        Entity(200, 400, crates),
        Entity(400, 400, crates),
        Entity(450, 300, crates),
        Entity(500, 200, crates),
        Entity(500, 30, crates)
    };

    MyCharacter Mine(350, 100, MC);
    bool gameRunning = true;
    bool gameOver = false;
    SDL_Event event;

    while (gameRunning) {
        frameStart = SDL_GetTicks();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                gameRunning = false;

            if (!gameOver) {
                Mine.handleEvent(event);
            }
        }

        if (!gameOver) {
            Mine.update(Crates, 8);
            Mine.checkCollisionWithBalls(ballLtoR, 2);
            Mine.checkCollisionWithBalls(ballRtoL, 2);

            for (int i = 0; i < 2; i++) {
                ballLtoR[i].updateLtoR(Crates, 8);
                ballRtoL[i].updateRtoL(Crates, 8);
            }

            if (Mine.getLifeMCINT() == 0) {
                gameOver = true;
            }
        }

        window.clear();
        gameMap.cldrawmap();

        for (int i = 0; i < 4; i++) {
            window.render(entities[i]);
        }
        for (int i = 0; i < 8; i++) {
            window.render(Crates[i]);
        }
        for (int i = 0; i < 2; i++) {
            window.render(ballLtoR[i]);
            window.render(ballRtoL[i]);
        }

        window.render(Mine);
        window.render(0, 0, Mine.getLifeMC(), font16, white);

        if (gameOver) {
            window.render(350 - 50, 320 - 16, "You die", font16, white);  // Adjust x and y coordinates to center the text
        }

        window.display();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    window.cleanUp();
    TTF_CloseFont(font16);
    SDL_Quit();

    return 0;
}
