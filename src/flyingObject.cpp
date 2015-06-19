#include "flyingObject.h"

flyingObject::flyingObject()
{
    //ctor
    direction.x=0.0;
    direction.y=1.0;
}

flyingObject::~flyingObject()
{
    //dtor
}
void flyingObject::move(sf::Vector2<float> direction){

    this->direction=direction;
    sf::Vector2<float> temp = this->direction;
    temp.x=this->direction.x*speed;
    temp.y=this->direction.y*speed;
    this->setPosition(this->getPosition()+temp);




}


void flyingObject::move(){


    sf::Vector2<float> temp = this->direction;
    temp.x=this->direction.x*speed;
    temp.y=this->direction.y*speed;
    this->setPosition(this->getPosition()+temp);



}

double flyingObject::getSpeed(){
    return this->speed;
}
void flyingObject::setSpeed(double speed){
    this->speed=speed;
}
