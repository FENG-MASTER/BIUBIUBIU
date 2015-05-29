#include "Enemy.h"
#include<Sky.h>
#include<iostream>
#define INIT_SPEED 2
#define INIT_FIRERATE 60
Enemy::Enemy(Sky* ownSky,int Score):Plane(ownSky)
{

    this->Score=Score;
    int *rendd=new int;
    this->fireRate=INIT_FIRERATE;
    this->setTexture(GTexture::ENEMY_NORMAL);
    this->setFireSpeed(10);
    this->health=Score*10;

    this->setPosition((*rendd)%560,10);
    delete rendd;
    _num =new int;
    this->setSpeed(INIT_SPEED);//设置敌机速度



    //ctor
}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::moveRand(){



        if((*_num)<0){(*_num)=-(*_num);}//这里必须为正数,否则会出现飞机不懂的现象


        if(num==1){
            int *ren=new int;


            switch((*ren)%5){

            case 0:
                direction='D';
                break;
            case 1:
                direction='A';
                 break;
            case 2:
                direction='S';
                break;
            case 3:
                direction='S';
                break;
            case 4:
                direction='S';
                break;

            }

            this->move(direction);
            num++;
        }else{
            num++;
            this->move(direction);

            if(num>=((*_num)%100)){
                _num =new int;
                num=1;

            }



        }









}

void Enemy::boomByState(int state){
    if(state==2){

        this->BOOM.play();

    }
    sf::Sprite boomImg;
    boomImg.setTexture(BOOMTEXTURE);

    boomImg.setScale(state/5.0,state/5.0);
    boomImg.setPosition(this->getPosition().x,this->getPosition().y);

    this->ownSky->window->draw(boomImg);

}
int Enemy::getScore(){
    return this->Score;
}
bool Enemy::fireRand(){
    int flat;
    int *rand=new int;
    flat=(*rand)%100;

    if((flat>0)&&(flat<(100*this->rateOfFire))){
        fire();


    }else{


    }



}



void Enemy::fire(){
//发射
    static int i=0;


    if(i>this->fireRate){
        Bullet *bullet=new Bullet(GTexture::BULLET);
        bullet->setSpeed(this->fireSpeed);
        bullet->setPosition(this->getPosition().x+20,this->getPosition().y);
        this->ownSky->addBullet(bullet,2);
        i=0;
    }else{
        i++;
    }


}
void Enemy::setFireRate(double rate){
    this->rateOfFire=rate;


}
