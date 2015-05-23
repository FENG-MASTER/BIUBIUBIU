#include "Enemy.h"
#include<Sky.h>

Enemy::Enemy(Sky* ownSky,int Score):Plane(ownSky)
{

    this->Score=Score;
    int *rendd=new int;
    this->fireSpeed=380;
    this->setTexture(GTexture::ENEMY_NORMAL);


    this->setPosition((*rendd)%600,10);
    delete rendd;

    this->setSpeed(5);//设置敌机速度

    //ctor
}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::moveRand(){

    //   srand((int)time(NULL));
      //  rand();


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

            if(num==50){
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
 //   boomImg.setPosition(this->getPosition().x+(this->getGlobalBounds().width/2.0),this->getPosition().y+(this->getGlobalBounds().height/2.0));
  // std::cout<<this->getPosition().x<<"|"<<this->getPosition().y<<"|"<<(this->getPosition().x+(this->getGlobalBounds().width/2.0))<<"|"<<(this->getPosition().y+(this->getGlobalBounds().height/2.0))<<std::endl;

    this->ownSky->window->draw(boomImg);

}
int Enemy::getScore(){
    return this->Score;
}
bool Enemy::fireRand(){
    int flat;
    int *rand=new int;
    flat=(*rand)%100;
    if(flat>0||flat<(100*this->rateOfFire)){
        fire();


    }else{


    }





}



void Enemy::fire(){
//发射

static int i=0;
    if(i>this->fireSpeed){
        Bullet *bullet=new Bullet(GTexture::BULLET);
        bullet->setSpeed(10);
        bullet->setPosition(this->getPosition().x+20,this->getPosition().y);
        this->ownSky->addBullet(bullet,2);
        i=0;
    }else{
        i++;
    }


}
