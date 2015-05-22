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

    protected:
    private:
        sf::Music &BOOM=Music::SOUND_BOOM;
        int Score;
        int num=1;
        char direction;
};

#endif // ENEMY_H
