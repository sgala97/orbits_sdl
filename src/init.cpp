#include "init.hpp"

bool init(SDL_Window *&window, char title[], int hegiht, int width){
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "Error inicializar SDL" << SDL_GetError() << std::endl;
        return false;
    }
    else if(!initWindow(window, title, hegiht, width)){
        return false;
    }
    else{
        return true;
    }
}

bool initWindow(SDL_Window *&window, char title[], int hegiht, int width){
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, width, hegiht, SDL_WINDOW_SHOWN); 
    if (window == NULL){
        std::cout << "Error: " << SDL_GetError() << std::endl;
        return false;
    }
    else{
        return true;
    }
}