#include "Plane.h"
#include<Sky.h>
#include<GTexture.h>

Plane::Plane(Sky* ownSky)
{

    //ctor
    this->ownSky=ownSky;
}

Plane::~Plane()
{
    //dtor
}
void Plane::fire(){
//发射



}



void Plane::setFireSpeed(int speed){
    this->fireSpeed=speed;
}


