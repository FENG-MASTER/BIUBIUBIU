#include "flyingObject.h"

flyingObject::flyingObject()
{
    //ctor
    direction.x=0;
    direction.y=1;
}

flyingObject::~flyingObject()
{
    //dtor
}
void flyingObject::move(char direction){



  if(direction=='A'||direction=='a'){
        this->setPosition(this->getPosition().x-this->speed,this->getPosition().y);

    }else if(direction=='D'||direction=='d'){
        this->setPosition(this->getPosition().x+this->speed,this->getPosition().y);
    }else if(direction=='S'||direction=='s'){
        this->setPosition(this->getPosition().x,this->getPosition().y+this->speed);

    }else if(direction=='W'||direction=='w'){
        this->setPosition(this->getPosition().x,this->getPosition().y-this->speed);

    }


}
int flyingObject::getSpeed(){
    return this->speed;
}
void flyingObject::setSpeed(int speed){
    this->speed=speed;
}
