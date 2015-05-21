#include "Player.h"

Player::Player(Sky* ownSky):Plane(ownSky)
{
    this->setTexture(this->texture);
    this->setScale(0.4,0.4);
    this->setPosition(200,680);
    //ctor
}

Player::~Player()
{
    //dtor
}
