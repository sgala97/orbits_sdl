#ifndef FUNCIONES
#define FUNCIONES
#pragma once
#include <SDL2/SDL.h>
#include <iostream>
Uint32 ColourToUint(int R, int G, int B, int A);

SDL_Colour UintToColour(Uint32 colour);
#endif