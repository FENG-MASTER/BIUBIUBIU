#include "Skill.h"
#include<unordered_set>
#include<Sky.h>
#include<Bullet.h>
#include<time.h>
Skill::Skill(Sky *Sky)
{
    //ctor
    this->ownSky=Sky;
}

Skill::~Skill()
{
    //dtor
}
void Skill::boom(){
    static int temp=10;
    srand((int)time(0));
    int a=rand();

    if(temp==1){

        for(int i=0;i<50;i++){
            Bullet *bullet=new Bullet(GTexture::BULLET2,50,sf::Vector2<float>(0.0,-1.0));

            if(a<0){
                a=-a;

            }
            bullet->setScale(0.5,0.5);

            bullet->setPosition(a%600,800);
             this->ownSky->bullets.insert(bullet);
             a=rand();

        }



    }else{

        temp--;
    }


}
