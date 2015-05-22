#ifndef ENEMY_H
#define ENEMY_H
#include<Plane.h>
#include <SFML/Audio.hpp>
#include<Music.h>
class Enemy :public Plane
{
    public:
        Enemy(Sky* ownSky,int Score);
        virtual ~Enemy();
        void moveRand(); //随机移动
        int state=0;//敌机状态 0正常 1-4爆炸 5死亡
        void boomByState(int state);
        int getScore();
        bool fireRand();
        void fire();

    protected:
    private:
        sf::Music &BOOM=Music::SOUND_BOOM;
        int Score;
        int num=1;//这个变量简单说是用来处理敌机的运行状态的, 判断啊敌机是否达到换方向运动的变量
        char direction;//敌机当前运动方向
        int rateOfFire;
};

#endif // ENEMY_H
