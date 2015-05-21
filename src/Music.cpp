#include "Music.h"

#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
sf::Music Music::MUSIC_BGM;
Music::Music()
{
    //ctor
}

Music::~Music()
{
    //dtor
}

void Music::load(){
    MUSIC_BGM.openFromFile("E:\\programmer\\BIUBIU\\res\\BGM1.flac");
}
