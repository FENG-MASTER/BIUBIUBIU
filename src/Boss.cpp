#include "Boss.h"
#include<Bullet.h>
#include<Sky.h>
#include<iostream>
Boss::Boss(Sky* ownSky,int Score,int level):Enemy(ownSky,Score)
{


    this->Score=level*50;
    this->health=level*3000;
    this->setPosition(200,0);
    this->setTexture(GTexture::ENEMY_BOSS,true);
    this->fireRate=int(20/level);
    ownSky->bossMission=true;


        //ctor
}

Boss::~Boss()
{
    //dtor
    ownSky->bossMission=false;
    for(int i=0;i<3;i++){

        ownSky->createItems(this->getPosition().x,this->getPosition().y);


    }
}
void Boss::fire(){

    static int i=0;


    if(i>this->fireRate){
        Bullet *bullet1=new Bullet(GTexture::BULLET_BOSS,this->ATK);
        bullet1->setSpeed(this->fireSpeed);
        bullet1->setPosition(this->getPosition().x+40,this->getPosition().y+100);
        Bullet *bullet2=new Bullet(GTexture::BULLET_BOSS,this->ATK);
        bullet2->setSpeed(this->fireSpeed);
        bullet2->setPosition(this->getPosition().x+180,this->getPosition().y+100);

        Bullet *bullet3=new Bullet(GTexture::BULLET_BOSS,this->ATK);
        bullet3->setSpeed(this->fireSpeed);
        bullet3->setPosition(this->getPosition().x+40,this->getPosition().y+100);
        Bullet *bullet4=new Bullet(GTexture::BULLET_BOSS,this->ATK);
        bullet4->setSpeed(this->fireSpeed);
        bullet4->setPosition(this->getPosition().x+180,this->getPosition().y+100);


            bullet1->move(sf::Vector2<float>(-0.5,-0.5));
        bullet2->move(sf::Vector2<float>(-0.5,-0.5));

        bullet3->move(sf::Vector2<float>(0.5,0.5));
        bullet4->move(sf::Vector2<float>(-0.5,0.5));
        bullet1->setScale(0.5,0.5);
        bullet2->setScale(0.5,0.5);
        bullet4->setScale(0.5,0.5);
        bullet3->setScale(0.5,0.5);
        this->ownSky->addBullet(bullet1,2);
        this->ownSky->addBullet(bullet2,2);
                this->ownSky->addBullet(bullet3,2);
        this->ownSky->addBullet(bullet4,2);
        i=0;
    }else{
        i++;
    }

}


bool Boss::checkBorder(int h,int w){


        if(this->getPosition().x<-5){

this->setPosition(w,this->getPosition().y);
            return false;
        }else if(this->getPosition().x>w){
 this->setPosition(0,this->getPosition().y);
            return false;
        }else if(this->getPosition().y>h){
this->setPosition(this->getPosition().x,-50);
            return false;
        }else if(this->getPosition().y<-60){
this->setPosition(this->getPosition().x,h);
            return false;
        }

        return false;







}
void Boss::moveRand(){



        if((*_num)<0){(*_num)=-(*_num);}//这里必须为正数,否则会出现飞机不懂的现象


        if(num==1){
            int *ren=new int;


            switch((*ren)%4){

            case 0:
                direction=sf::Vector2<float>(1.0,0);
                break;
            case 1:
                direction=sf::Vector2<float>(-1.0,0);
                 break;
            case 2:
                direction=sf::Vector2<float>(0,-1);
                break;
            case 3:
                direction=sf::Vector2<float>(0,1);
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


void Boss::boomByState(int state){

    if(state==2){

        this->BOOM.play();

    }
    sf::Sprite boomImg;
    boomImg.setTexture(BOOMTEXTURE);

    boomImg.setScale(state/2.0,state/2.0);
    boomImg.setPosition(this->getPosition().x,this->getPosition().y);

    this->ownSky->window->draw(boomImg);

}
