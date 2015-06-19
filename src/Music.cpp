#include "Music.h"

#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#define BOOMVOLUM 30
#define FIREVOLUM 10
sf::Music Music::MUSIC_BGM;
sf::Music Music::SOUND_BOOM;
sf::Music Music::SOUND_FIRE;
sf::Music Music::MUSIC_LOAD;
Music::Music()
{
    //ctor
}

Music::~Music()
{
    //dtor
}

void Music::load(){
    MUSIC_BGM.openFromFile("res\\BGM1.flac");
    SOUND_BOOM.openFromFile("res\\BOOM.wav");
    SOUND_FIRE.openFromFile("res\\FIRE.ogg");
    MUSIC_LOAD.openFromFile("res\\LOADING.flac");
    SOUND_FIRE.setVolume(FIREVOLUM);
    SOUND_BOOM.setVolume(BOOMVOLUM);
}
