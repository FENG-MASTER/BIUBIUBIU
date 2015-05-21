#include "Bullet.h"

Bullet::Bullet(sf::Texture texture)
{
    //ctor
    this->texture=texture;
    this->setTexture(this->texture);


}

Bullet::~Bullet()
{
    //dtor
}
void Bullet::move(char direction){
    if(direction=='S'||direction=='s'){
         this->setPosition(this->getPosition().x,this->getPosition().y-this->getSpeed());
    }else if(direction=='W'||direction=='w'){
        this->setPosition(this->getPosition().x,this->getPosition().y+this->getSpeed());
    }

}
void Bullet::setSpeed(int speed){
    this->speed=speed;
}
int Bullet::getSpeed(){
    return this->speed;
}
