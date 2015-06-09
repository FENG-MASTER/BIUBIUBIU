#include "Bullet.h"

Bullet::Bullet(sf::Texture texture,int ATK,sf::Vector2<float> direction)
{
    //ctor
    this->ATK=ATK;
    this->texture=texture;
    this->setTexture(this->texture);
    this->direction=direction;


}

Bullet::~Bullet()
{
    //dtor
}
