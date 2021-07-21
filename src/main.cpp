#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "init.hpp"
#include <string>

// std naming
using namespace std;

// screen size
const int WIDTH = 400; 
const int HEIGHT = 400;  

enum teclas{
    defaultkey, up, rightKey, down, leftKey, total
};

int main(int argc, char* args[]){
    SDL_Window* window;
    if (!init(window, "titulo", WIDTH, HEIGHT)) return 1;
    SDL_Surface* surface = SDL_GetWindowSurface( window );
    IMG_Init(IMG_INIT_PNG);
    SDL_Surface* images[total];
    SDL_Surface* image; 
    for(int i=0; i<total; i++)
    {
        image = IMG_Load((string("assets/") + to_string(i) + string(".png")).c_str());
        images[i] = SDL_ConvertSurface(image, surface->format, 0);

    }
    SDL_Event *event = new SDL_Event();
    bool quit = false;
    while(!quit){
        while(SDL_PollEvent(event) != NULL){
            if(event->type == SDL_QUIT)
            {
                quit = true;
            }
            else if(event->type == SDL_KEYDOWN){
                switch (event->key.keysym.sym)
                {
                    case SDLK_UP:
                        image = images[up];
                    break;
                
                    case SDLK_RIGHT:
                        image = images[rightKey];
                    break;

                    case SDLK_DOWN:
                        image = images[down];
                    break;

                    case SDLK_LEFT:
                        image = images[leftKey];
                    break;

                    default:
                    break;
                }
            }
            else if(event->type == SDL_KEYUP){
                image = images[defaultkey];
            }
        }
        SDL_BlitSurface(image, NULL, surface, NULL);
        SDL_UpdateWindowSurface(window);
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}