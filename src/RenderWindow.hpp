#ifndef RENDERWINDOW
#define RENDERWINDOW
#pragma once
#include <SDL2/SDL.h>
#include <iostream>
class RenderWindow{
    private:
        SDL_Window* window;
        SDL_Renderer* render;
    public:
        RenderWindow(char* title, int height, int width);    
        bool isCreated();    
        void update();
        void clear();
        void copyTexture(SDL_Texture* textura, SDL_Rect* srcRect, SDL_Rect* desRect);
        SDL_Renderer* getRender();
        ~RenderWindow();

};

#endif
