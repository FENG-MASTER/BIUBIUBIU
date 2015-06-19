#include "GTexture.h"
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>


sf::Texture GTexture::SKY;
sf::Texture GTexture::SKY_BOOM;
sf::Texture GTexture::PLAYER_NORMAL;
sf::Texture GTexture::PLAYER_NULL;
sf::Texture GTexture::BULLET;
sf::Texture GTexture::BULLET2;
sf::Texture GTexture::ENEMY_NORMAL;
sf::Texture GTexture::ENEMY_BOOM1;
sf::Texture GTexture::ITEM_HEALTH;
sf::Texture GTexture::ITEM_SPEED;
sf::Texture GTexture::ITEM_RAND;
sf::Texture GTexture::ITEM_ATK;
sf::Texture GTexture::ITEM_BUTTET_SPEED;
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

    SKY.loadFromFile("res\\SKY.jpg");
    SKY_BOOM.loadFromFile("res\\SKY_BOOM.jpg");
    PLAYER_NORMAL.loadFromFile("res\\plane_1.png",sf::IntRect(2,9,420,272));
    BULLET.loadFromFile("res\\bullet.png",sf::IntRect(313,230,31,31));
    ENEMY_NORMAL.loadFromFile("res\\plane_2.png",sf::IntRect(390,549,72,63));
    ENEMY_BOOM1.loadFromFile("res\\boom.png");
    BULLET2.loadFromFile("res\\bullet.png",sf::IntRect(393,0,48,94));
    ITEM_HEALTH.loadFromFile("res\\plane_1.png",sf::IntRect(395,750,55,55));//生命道具
    ITEM_SPEED.loadFromFile("res\\plane_1.png",sf::IntRect(456,807,52,54));//加速道具
    ITEM_RAND.loadFromFile("res\\item.png");
    ITEM_ATK.loadFromFile("res\\item_2.png");
    LOADING.loadFromFile("res\\LOADING.png");
    ENEMY_2.loadFromFile("res\\plane_2.png",sf::IntRect(276,473,103,74));
    ICO.loadFromFile("res\\ICO.png");//窗口图标
    ENEMY_BOSS.loadFromFile("res\\BOSS.png");//BOSS
    BULLET_BOSS.loadFromFile("res\\bullet.png",sf::IntRect(365,439,42,90));//BOSS的子弹

    PLAYER_NULL.loadFromFile("res\\NULL.png");//闪烁效果,这个是空白文件
    ITEM_BUTTET_SPEED.loadFromFile("res\\plane_1.png",sf::IntRect(496,866,52,52));
}
