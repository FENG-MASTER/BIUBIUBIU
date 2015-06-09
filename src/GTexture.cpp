#include "GTexture.h"
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>


sf::Texture GTexture::SKY;
sf::Texture GTexture::PLAYER_NORMAL;
sf::Texture GTexture::BULLET;
sf::Texture GTexture::BULLET2;
sf::Texture GTexture::ENEMY_NORMAL;
sf::Texture GTexture::ENEMY_BOOM1;
sf::Texture GTexture::ITEM_HEALTH;
sf::Texture GTexture::ITEM_SPEED;
sf::Texture GTexture::ITEM_RAND;
sf::Texture GTexture::ITEM_ATK;
sf::Texture GTexture::LOADING;
sf::Texture GTexture::ENEMY_2;
sf::Texture GTexture::BULLET_BOSS;
sf::Texture GTexture::ENEMY_BOSS;
sf::Image GTexture::ICO;
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
    ITEM_HEALTH.loadFromFile("E:\\programmer\\BIUBIU\\res\\plane_1.png",sf::IntRect(395,750,55,55));
    ITEM_SPEED.loadFromFile("E:\\programmer\\BIUBIU\\res\\plane_1.png",sf::IntRect(456,807,52,54));
    ITEM_RAND.loadFromFile("E:\\programmer\\BIUBIU\\res\\item.png");
    ITEM_ATK.loadFromFile("E:\\programmer\\BIUBIU\\res\\item_2.png");
    LOADING.loadFromFile("E:\\programmer\\BIUBIU\\res\\LOADING.png");
    ENEMY_2.loadFromFile("E:\\programmer\\BIUBIU\\res\\plane_2.png",sf::IntRect(276,473,103,74));
    ICO.loadFromFile("E:\\programmer\\BIUBIU\\res\\ICO.png");
    ENEMY_BOSS.loadFromFile("E:\\programmer\\BIUBIU\\res\\BOSS.png");
    BULLET_BOSS.loadFromFile("E:\\programmer\\BIUBIU\\res\\bullet.png",sf::IntRect(365,439,42,90));

}
