#ifndef BOSS_H
#define BOSS_H
#include<Enemy.h>

class Boss:public Enemy
{
    public:
        Boss(Sky* ownSky,int Score,int level);
        virtual ~Boss();
        void fire();
        bool checkBorder(int h,int w);
        void moveRand(); //Ëæ»úÒÆ¶¯
        void boomByState(int state);
    protected:
    private:

};

#endif // BOSS_H
