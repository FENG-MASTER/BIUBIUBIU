#ifndef ENEMY_H
#define ENEMY_H
#include<Plane.h>

class Enemy :public Plane
{
    public:
        Enemy(Sky* ownSky);
        virtual ~Enemy();
        void moveRand(); //��������ƶ�����
    protected:
    private:
};

#endif // ENEMY_H
