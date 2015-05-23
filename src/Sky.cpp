#include "Sky.h"
#include<Player.h>
//#include<Bullet.h>
#include<iostream>
#include<Enemy.h>

Sky::Sky(sf::RenderWindow *window)
{
    this->window=window;

    this->setTexture(this->texture);

    this->setScale(1.0*this->window->getSize().x/this->texture.getSize().x,1.0*this->window->getSize().y/this->texture.getSize().y);//ʵ�ֱ���SKYȫ��
    //ctor
}

Sky::~Sky()
{
    //dtor
}
void Sky::add(Player *Player){
   // this->planes.insert(Player);
    this->player = Player;

}

void Sky::refresh(){



    this->window->clear();
    this->window->draw(*this);
    this->window->draw(*(this->player));


    auto enemy = this->planes.begin();
    while(enemy!=(this->planes.end()))
    {
         auto temp=enemy;


        /*
            ���ﴦ���µл��ı�Ե����0.0����д������������,��

            Ҳ��Ϊ�˼���ѭ��������,����ʾ���ж�д��һ��

        */

        if((*enemy)->state>=1&&(*enemy)->state<=4){
            (*enemy)->boomByState(((*enemy)->state)++);

            break;
        }else if((*enemy)->state==5){
            delete *enemy;
            enemy = (this->planes).erase(enemy);
            break;
        }

        (*enemy)->moveRand();
        if((*enemy)->getPosition().x<0){
            (*enemy)->setPosition(580,(*enemy)->getPosition().y);

        }else if((*enemy)->getPosition().x>580){
            (*enemy)->setPosition(-5,(*enemy)->getPosition().y);
        }else if((*enemy)->getPosition().y>700){
            delete *enemy;
           enemy = (this->planes).erase(enemy);
           break;
        }

          //�������ж��Ƿ�л��е�
   //    int bre=0;//break˫��ѭ���õı��
        for(auto sprite = this->bullets.begin(); sprite!=(this->bullets.end());){
                if((*enemy)->getGlobalBounds().intersects((*sprite)->getGlobalBounds())){
                        (*enemy)->state=1;
                        this->player->addScore((*enemy)->getScore());


                        this->bullets.erase(sprite);//�ӵ���ʧ

                   //     bre=1;//�򿪱��
                        break;

                }
                sprite++;


        }
      //  if(bre==1){break;}//break����ѭ����
        this->enemyRandFire();

        this->window->draw(**enemy);


        if(temp==enemy){enemy++;}//���ڲ�����ô�������˫��ѭ����enemy++����,ǿ��ʹ��һ��������¼��ǰ��ȡֵ,Ȼ��



    }

    for(auto &sprite : this->bullets){

        this->window->draw(*sprite);
    }


    for(auto &sprite : this->enemyBullets){

        this->window->draw(*sprite);
    }



}
void Sky::addBullet(Bullet* bullet,int flat){
    switch (flat)
    {
        case 1:
             this->bullets.insert(bullet);//����ӵ�������ӵ�
             break;
        case 2:

             this->enemyBullets.insert(bullet);//����ӵ��������ӵ�
             break;


    }

}

void Sky::moveBullet(){

    for(auto &bullet : this->bullets){
        bullet->move('s');
    }
     for(auto &bullet : this->enemyBullets){

        bullet->move('W');
    }

}
void Sky::clearBullet(){

    for(auto bullet = this->bullets.begin(); bullet!=(this->bullets.end());){

        if((*bullet)->getPosition().y<0){

            delete *bullet;

            bullet = (this->bullets).erase(bullet);

        }else{
        bullet++;
        }

    }

}

void Sky::createEnemies(){

    static int count=0;

    if(++count>=200){
        Enemy* enemy = new Enemy(this,10);
        this->planes.insert(enemy);
        count = 0;
    }
}

void Sky::enemyRandFire(){

    for(auto enemy = this->planes.begin(); enemy!=(this->planes.end());){
        (*enemy)->fireRand();
        enemy++;
    }

}
bool Sky::isEnd(){
    for(auto &bullet : this->enemyBullets){
        if((bullet)->getGlobalBounds().intersects((this->player)->getGlobalBounds())){
               return true;
        }

    }
    for(auto &enemy : this->planes){
        if((enemy)->getGlobalBounds().intersects((this->player)->getGlobalBounds())){
               return true;
        }
    }

    return false;

}
void Sky::clearEnemyAndBullet(){
    enemyBullets.clear();
    planes.clear();
}
