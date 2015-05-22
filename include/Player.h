#ifndef PLAYER_H
#define PLAYER_H
//#include <SFML/Graphics.hpp>
#include "Plane.h"
//#include"GTexture.h"
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
    protected:
    private:
        int score=0;
        int fireSpeed=2;
        sf::Texture texture=GTexture::PLAYER_NORMAL;//Íæ¼Ò·É»úÎÆÀí
        sf::Music &FIRE=Music::SOUND_FIRE;

};

#endif // PLAYER_H
