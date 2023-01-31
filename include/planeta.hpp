#ifndef PLANETA
#define PLANETA
#pragma once
#include "funciones.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <math.h>
struct Vector {
  double x, y;
};
class Planeta {
private:
  Vector position;
  Vector v;
  int r;
  double modulus;

public:
  Planeta();
  Planeta(int x, int y, int r);
  void drawPlaneta(SDL_Renderer *render);
  void updatePlaneta(Vector *positionP, double g, double delta);
  void setV(Vector *v);
  Vector unitaryVector(Vector *positionP);
  bool destroy();
};

#endif