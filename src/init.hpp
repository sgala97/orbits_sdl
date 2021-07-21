#ifndef INIT
#define INIT
#pragma once
#include <iostream>
#include <SDL2/SDL.h>
bool init(SDL_Window *&window, char title[], int hegiht, int width);
bool initWindow(SDL_Window *&window, char title[], int hegiht, int width);
#endif