#ifndef MUSIC_H
#define MUSIC_H
#include <SFML/Audio.hpp>

class Music
{
    public:
        Music();
        virtual ~Music();

        static sf::Music MUSIC_BGM;//背景音乐
        static sf::Music MUSIC_LOAD;
        static sf::Music SOUND_BOOM;
        static sf::Music SOUND_FIRE;
        static void load();


    protected:
    private:
};

#endif // MUSIC_H
