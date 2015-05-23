#include "Player.h"
#include<Bullet.h>
#include<Sky.h>
#include <SFML/System.hpp>

Player::Player(Sky* ownSky):Plane(ownSky)
{
    this->setTexture(this->texture);
    this->setScale(0.4,0.4);
    this->setPosition(200,680);
    this->setSpeed(30);



    //ctor
}

Player::~Player()
{
    //dtor
}
void Player::fire(){
//·¢Éä

    static int i=0;
    if(i>this->fireSpeed){
        FIRE.play();
        Bullet *bulletL=new Bullet(GTexture::BULLET);
        Bullet *bulletR=new Bullet(GTexture::BULLET);
        bulletL->setPosition(this->getPosition().x,this->getPosition().y);
        bulletR->setPosition(this->getPosition().x+120,this->getPosition().y);
        this->ownSky->addBullet(bulletL,1);
        this->ownSky->addBullet(bulletR,1);
        i=0;
    }else{
        i++;
    }


}

void Player::addScore(int score){
    this->score+=score;
}


int Player::getScore(){
    return this->score;
}
void Player::clearScore(){
    this->score=0;
}
int Player::getLife(){
    return lifeTime;
}

bool Player::dead(){
    this->BOOM.play();
    sf::Sprite boomImg;
    boomImg.setTexture(BOOMTEXTURE);
    BOOMTEXTURE.isRepeated();

    boomImg.setPosition(this->getPosition().x,this->getPosition().y);

    ownSky->window->draw(boomImg);

    ownSky->window->display();
    sf::Time s = sf::seconds(1);
    sf::sleep(s);
    lifeTime--;
    return lifeTime==0;

}
