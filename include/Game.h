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


    protected:
    private:
        void playMusic();
        void stopMusic();
        sf::Music &BGM=Music::MUSIC_BGM;//游戏BGM

        Sky* sky;


};

#endif // GAME_H
