#include "Sky.h"
#include<Player.h>
//#include<Bullet.h>
#include<iostream>
#include<Enemy.h>
Sky::Sky(sf::RenderWindow *window)
{
    this->window=window;
    this->setTexture(this->texture);
    this->setScale(1.0*this->window->getSize().x/this->texture.getSize().x,1.0*this->window->getSize().y/this->texture.getSize().y);//实现背景SKY全屏
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
    for(auto &enemy : this->planes){
        enemy->moveRand();
        /*
            这里处理下敌机的边缘问题0.0我先写在这个方法里吧,懒

        */


        if(enemy->getPosition().x<0){
            enemy->setPosition(580,enemy->getPosition().y);

        }else if(enemy->getPosition().x>580){
            enemy->setPosition(-5,enemy->getPosition().y);
        }




        this->window->draw(*enemy);

    }

    for(auto &sprite : this->bullets){

        this->window->draw(*sprite);
    }


}
void Sky::addBullet(Bullet* bullet){
    this->bullets.insert(bullet);
}

void Sky::moveBullet(){
    for(auto &bullet : this->bullets){
        bullet->move('s');

    }

}
void Sky::clearBullet(){

    for(auto bullet = this->bullets.begin(); bullet!=(this->bullets.end());){

        if((*bullet)->getPosition().y<0){

            delete *bullet;
           // this->bullets.erase(*bullet);
            bullet = (this->bullets).erase(bullet);

        }else{
        bullet++;
        }

    }

}

void Sky::createEnemies(){

    static int count=0;


    if(++count>=100){
        Enemy* enemy = new Enemy(this);
        this->planes.insert(enemy);


        count = 0;
    }



}


bool enemyNeedToBeclear(Enemy *enemy){


}
