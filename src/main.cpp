// Two planets orbiting one central planet
#include <iostream>
#include <string>
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include "init.hpp"
#include "RenderWindow.hpp"
#include "funciones.hpp"
#include "planeta.hpp"

// Screen size
const int WIDTH = 1920; 
const int HEIGHT = 1080;  

int main(int argc, char* args[]){
    // Init sdl 
    if (!init()) return 1;
    // Create full screen window
    RenderWindow window("orbit animation", HEIGHT, WIDTH, SDL_WINDOW_FULLSCREEN);

    // Check if window started correctly
    if(!window.isCreated())
    {
        std::cout << "Error SDL" << SDL_GetError << std::endl;
        return 1;
    }

    // Create even
    SDL_Event *event = new SDL_Event();
    bool quit = false;


    Planeta planeta(700, 540, 10);
    Vector v;
    v.x = 0;
    v.y = 80;
    planeta.setV(&v);

    Planeta planeta1(750, 540, 10);
    v.x = 0;
    v.y = 120;
    planeta1.setV(&v);


    Planeta planeta2(500, 540, 20);
    v.x = 0;
    v.y = 98;
    planeta2.setV(&v);

    unsigned int delta1 = 0;
    unsigned int delta2 = SDL_GetTicks();
    unsigned int delta;

    Vector positionP;
    positionP.x = WIDTH/2;
    positionP.y = HEIGHT/2;

    int flags;

    while(!quit){
        while(SDL_PollEvent(event) != NULL){
            if(event->type == SDL_QUIT){
                quit = true;
            }
            else if(event->key.keysym.sym == SDLK_ESCAPE){
                quit = true;
            }
        }
        flags = SDL_GetWindowFlags(window.getWindow());
        delta2 = delta1;
        delta1 = SDL_GetTicks();
        delta = SDL_abs(delta1-delta2);
        double deltaS = delta/1000.0f;

        if(true){
            SDL_SetRenderDrawColor( window.getRender(), 0x00, 0x00, 0x00, 0x00 );
            window.clear();
            planeta.updatePlaneta(&positionP, 4000000.0f, deltaS);
            planeta1.updatePlaneta(&positionP, 4000000.0f, deltaS);
            planeta2.updatePlaneta(&positionP, 4000000.0f, deltaS);
            planeta.drawPlaneta(window.getRender());
            planeta1.drawPlaneta(window.getRender());
            planeta2.drawPlaneta(window.getRender());
            filledCircleColor(window.getRender(), WIDTH/2, HEIGHT/2, 30, ColourToUint(200, 0, 255, 255));
            window.update();
        }
    }
    close();
    return 0;
}
