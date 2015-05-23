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
    Bullet *bullet=new Bullet(GTexture::BULLET);
    bullet->setSpeed(fireSpeed);
    bullet->setPosition(this->getPosition().x+60,this->getPosition().y);
    this->ownSky->addBullet(bullet,1);



}

void Plane::move(char direction){

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

void Plane::setSpeed(int speed){
    this->speed=speed;
}
void Plane::setFireSpeed(int speed){
    this->fireSpeed=speed;
}

