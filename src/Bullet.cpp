#include "Bullet.h"

Bullet::Bullet(sf::Texture texture,int ATK)
{
    //ctor
    this->ATK=ATK;
    this->texture=texture;
    this->setTexture(this->texture);


}

Bullet::~Bullet()
{
    //dtor
}
