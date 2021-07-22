#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "init.hpp"
#include "RenderWindow.hpp"
#include <string>

// screen size
const int WIDTH = 400; 
const int HEIGHT = 400;  

enum teclas{
    defaultkey, up, right, down, left, total
};

int main(int argc, char* args[]){
    if (!init()) return 1;
    RenderWindow window("titulo", HEIGHT, WIDTH);
    if(!window.isCreated())
    {
        std::cout << "Error SDL" << SDL_GetError << std::endl;
        return 1;
    }
    SDL_Event *event = new SDL_Event();
    SDL_Texture* textura = IMG_LoadTexture(window.getRender(),"assets/hola.png");
    bool quit = false;
    while(!quit){
        while(SDL_PollEvent(event) != NULL){
            if(event->type == SDL_QUIT)
            {
                quit = true;
            }
        }
        window.clear();
        window.copyTexture(textura, NULL, NULL);
        window.update();
    }
    close();
    return 0;
}