#include "planeta.hpp"

Planeta::Planeta(){}

Planeta::Planeta(int x, int y, int r)
{
    this->position.x = x;
    this->position.y = y;
    this->r = r;
}

void Planeta::drawPlaneta(SDL_Renderer* render){
    filledCircleColor(render, position.x, position.y, r, ColourToUint(255, 0, 0, 255));
}

Vector Planeta::unitaryVector(Vector* positionP){
    Vector unitary;
    unitary.x = positionP->x - position.x;
    unitary.y = positionP->y - position.y;
    modulus = sqrt(powf32(unitary.x,2)+powf32(unitary.y,2));
    unitary.x /= modulus;
    unitary.y /= modulus;
    return unitary;
}

void Planeta::setV(Vector* v){
    this->v.x = v->x;
    this->v.y = v->y;
}

void Planeta::updatePlaneta(Vector* positionP, double g, double delta)
{
    position.x += (v.x * delta);
    position.y += (v.y * delta);

    Vector unitary = unitaryVector(positionP);

    float constante = g/pow(modulus,2);
    v.x += ((constante*unitary.x)*delta);
    v.y += ((constante*unitary.y)*delta);
}

bool Planeta::destroy(){
    if (position.x > 1920 || position.x < 0 || position.y >1080 || position.y < 0){
        return true;
    }
    else{
        return false;
    }
}