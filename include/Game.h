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
        void pause();
        void showInfo();


    protected:
    private:
        void playMusic();
        void stopMusic();
        sf::Music &BGM=Music::MUSIC_BGM;//游戏BGM
        sf::Font font;//显示字体
        sf::Text Score;
        int lifeRemain;

        Sky* sky;


};

#endif // GAME_H
