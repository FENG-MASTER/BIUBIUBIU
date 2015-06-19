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
       virtual void moveRand(); //随机移动
        int state=0;//敌机状态 0正常 1-4爆炸 5死亡
       virtual void boomByState(int state);
        int getScore();
        bool fireRand();
        void fire();
        void setFireRate(double rate);
        int health;
        int ATK=10;
        virtual bool checkBorder(int w,int h);


    protected:

        int fireRate;
        int Score;
        int num=1;//这个变量简单说是用来处理敌机的运行状态的, 判断啊敌机是否达到换方向运动的变量
        int *_num;
        sf::Vector2<float> direction;//敌机当前随机运动方向
        double rateOfFire=0.5;//

    private:





};

#endif // ENEMY_H
