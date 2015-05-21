#ifndef ENEMY_H
#define ENEMY_H
#include<Plane.h>

class Enemy :public Plane
{
    public:
        Enemy(Sky* ownSky);
        virtual ~Enemy();
        void moveRand(); //敌人随机移动函数
    protected:
    private:
};

#endif // ENEMY_H
