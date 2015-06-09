#include "Sky.h"
#include<Player.h>
#include<iostream>
#include<Enemy.h>
#include<Boss.h>
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






    for(auto enemy = this->planes.begin();enemy!=(this->planes.end());)
    {

         auto temp=enemy;




        /*
            这里处理下敌机的边缘问题0.0我先写在这个方法里吧,懒

            也是为了减少循环检查次数,把显示和判断写在一起

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
        if((*enemy)->getPosition().x<-6){
            (*enemy)->setPosition(570,(*enemy)->getPosition().y);

        }else if((*enemy)->getPosition().x>580){
            (*enemy)->setPosition(-1,(*enemy)->getPosition().y);
        }else if((*enemy)->getPosition().y>700){
            delete *enemy;
           enemy = (this->planes).erase(enemy);
           break;
        }









          //这里是判断是否敌机中弹



        for(auto sprite = this->bullets.begin(); sprite!=(this->bullets.end());){
                if((*enemy)->getGlobalBounds().intersects((*sprite)->getGlobalBounds())&&(((*enemy)->health-=(*sprite)->ATK)<0)){
                        (*enemy)->state=1;
                        this->player->addScore((*enemy)->getScore());
                        createItems((*enemy)->getPosition().x,(*enemy)->getPosition().y);


                        this->bullets.erase(sprite);//子弹消失


                        break;

                }
                sprite++;


        }



        this->window->draw(**enemy);




        if(temp==enemy){++enemy;}//由于不懂怎么处理这个双重循环的enemy++问题,强行使用一个变量记录先前的取值,然后



    }

    for(auto &sprite : this->bullets){

        this->window->draw(*sprite);
    }


    for(auto &sprite : this->enemyBullets){

        this->window->draw(*sprite);
    }

    for(auto &item : this->items){

        this->window->draw(*item);
    }




}
void Sky::addBullet(Bullet* bullet,int flat){
    switch (flat)
    {
        case 1:
             this->bullets.insert(bullet);//添加子弹到玩家子弹
             break;
        case 2:

             this->enemyBullets.insert(bullet);//添加子弹到敌人子弹
             break;


    }

}

void Sky::moveBullet(){

    for(auto &bullet : this->bullets){
        bullet->move('W');
    }
     for(auto &bullet : this->enemyBullets){

        bullet->move('S');
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

    if(++count>=createRate){
        Enemy* enemy1 = new Enemy(this,10);
        Enemy* enemy2 = new Enemy(this,10);
        enemy1->setSpeed(enemySpeed);
        enemy2->setSpeed(enemySpeed);
        this->planes.insert(enemy1);
        this->planes.insert(enemy2);
        count = 0;
    }







}

void Sky::enemyRandFire(){

    for(auto enemy = this->planes.begin(); enemy!=(this->planes.end());){
        (*enemy)->setFireRate(this->enemyFireRate);
        (*enemy)->setFireSpeed(this->enemyBulletSpeed);
        (*enemy)->fireRand();
        enemy++;
    }

}
bool Sky::isEnd(){
return false;
    if(loading){
        return false;
    }

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

void Sky::createItems(int x,int y){
    srand(time(NULL));

    if((rand()%20)==1||(rand()%20)==2){

        Item *item=new Item(x,y);
        items.insert(item);

    }



}





void Sky::itemMoveAndCheak(){

    for(auto &item : this->items){
        item->moveRand();
        if(item->getGlobalBounds().intersects(this->player->getGlobalBounds())){
            //吃到道具

                if(item->getFlat==0){
                    item->getSomething(this);

                }

                    if(item->showItemIcon()){
                        delete item;
                        this->items.erase(item);
                        break;

                    }




        }
            //处理物品边界问题

        if(item->getPosition().x>580){
                item->setPosition(5,item->getPosition().y);

        }else if(item->getPosition().x<0){
                item->setPosition(570,item->getPosition().y);
        }


    }
}


void Sky::clearEverything(){

    for(auto &bullet : this->enemyBullets){
        delete bullet;

    }
    for(auto &enemy : this->planes){
        delete enemy;
    }
    for(auto &item : this->items){
        delete item;
    }





    enemyBullets.clear();
    bullets.clear();
    planes.clear();
    items.clear();
}
void Sky::createBoss(int level){
        Boss* boss = new Boss(this,10);
        boss->setSpeed(level);

        this->planes.insert(boss);


}



 void Sky::setEnemyCreateRate(int rate){
    this->createRate=rate;

 }
void Sky::setEnemySpeed(int speed){
    this->enemySpeed=speed;

}
void Sky::setEnemyFireRate(double rate){
    this->enemyFireRate=rate;

}
void Sky::setEnemyBulletSpeed(int speed){
    this->enemyBulletSpeed=speed;

}
