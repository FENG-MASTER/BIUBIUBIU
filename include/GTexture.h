#ifndef GTEXTURE_H
#define GTEXTURE_H
#include <SFML/Graphics.hpp>
/*
用于统一管理纹理

*/
class GTexture
{
    public:
        GTexture();
        virtual ~GTexture();

        static sf::Texture PLAYER_NORMAL;
        static sf::Texture PLAYER_BOOM1;
        static sf::Texture PLAYER_BOOM2;
        static sf::Texture PLAYER_BOOM3;

        static sf::Texture ENEMY_NORMAL;
        static sf::Texture ENEMY_BOOM1;
        static sf::Texture ENEMY_2;
        static sf::Texture ENEMY_BOSS;

        static sf::Texture BULLET;
        static sf::Texture BULLET2;
        static sf::Texture BULLET_BOSS;

        static sf::Texture ITEM_HEALTH;
        static sf::Texture ITEM_SPEED;
        static sf::Texture ITEM_RAND;
        static sf::Texture ITEM_ATK;

        static sf::Texture SKY;
        static sf::Image ICO;


        static sf::Texture LOADING;


        static void load();
    protected:
    private:
};

#endif // GTEXTURE_H
