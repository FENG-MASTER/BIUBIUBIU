#include "Enemy.h"

Enemy::Enemy(Sky* ownSky):Plane(ownSky)
{

    int *rendd=new int;
    this->setTexture(GTexture::ENEMY_NORMAL);


    this->setPosition((*rendd)%600,10);

    this->setSpeed(35);//设置敌机速度

    //ctor
}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::moveRand(){
    static int count=0;

    srand((unsigned) time(NULL));


    if(++count>=10){
        int *ren=new int;
        char direction;

        switch(int((*ren)%3)){

        case 0:
            direction='S';
            break;
        case 1:
            direction='A';
             break;
        case 2:
            direction='D';
            break;

        }
        this->move(direction);


        count = 0;

    }

}
