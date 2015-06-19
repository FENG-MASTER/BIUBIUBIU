#ifndef PLAYER_H
#define PLAYER_H

#include "Plane.h"

#include<Music.h>


class Player :public Plane
{
    public:
        Player(Sky* ownSky);
        virtual ~Player();
        void fire();
        void addScore(int score);
        int getScore();
        void clearScore();

        bool dead();
        void init();

        void setfireDensity(int de);//����ᴦ���±߽�,������̫��
        int getfireDensity();

        int lifeTime=3;
        int ATK=5;
        int noEnemyCanFight=-1;
friend class Sky;
    protected:
    private:
        int fireDensity=35;
        int score=0;


        sf::Texture texture=GTexture::PLAYER_NORMAL;//��ҷɻ�����
        sf::Music &FIRE=Music::SOUND_FIRE;


};

#endif // PLAYER_H
