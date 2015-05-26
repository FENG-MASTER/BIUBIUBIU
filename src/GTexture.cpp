#include "GTexture.h"
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>


sf::Texture GTexture::SKY;
sf::Texture GTexture::PLAYER_NORMAL;
sf::Texture GTexture::BULLET;
sf::Texture GTexture::BULLET2;
sf::Texture GTexture::ENEMY_NORMAL;
sf::Texture GTexture::ENEMY_BOOM1;

GTexture::GTexture()
{
    //ctor
}

GTexture::~GTexture()
{
    //dtor
}
void GTexture::load(){
    SKY.loadFromFile("E:\\programmer\\BIUBIU\\res\\SKY.jpg");
    PLAYER_NORMAL.loadFromFile("E:\\programmer\\BIUBIU\\res\\plane_1.png",sf::IntRect(2,9,420,272));
    BULLET.loadFromFile("E:\\programmer\\BIUBIU\\res\\bullet.png",sf::IntRect(313,230,31,31));
    ENEMY_NORMAL.loadFromFile("E:\\programmer\\BIUBIU\\res\\plane_2.png",sf::IntRect(390,549,72,63));
    ENEMY_BOOM1.loadFromFile("E:\\programmer\\BIUBIU\\res\\boom.png");
    BULLET2.loadFromFile("E:\\programmer\\BIUBIU\\res\\bullet.png",sf::IntRect(393,0,48,94));




}
