#ifndef GAME_H
#define GAME_H
#include <SFML/Audio.hpp>
#include<Sky.h>
#include<Music.h>

class Game
{
    public:
        Game(Sky *sky);
        virtual ~Game();
        void start();


        void init();



    protected:
    private:
        void showInfo();
        void showGameOver();
        void cheakNextMission();
        int MissionOfNow=0;
        void playMusic();
        void stopMusic();
        sf::Music &BGM=Music::MUSIC_BGM;//游戏BGM
        sf::Text Score;
        sf::Text GameOver_Text;
        int lifeRemain;
        int gameOverFlat=0;
        int waitingForReset=0;


        Sky* sky;


};

#endif // GAME_H
