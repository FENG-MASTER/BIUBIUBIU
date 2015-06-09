#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include<GTexture.h>
#include<flyingObject.h>
class Bullet:public flyingObject
{
    public:
        Bullet(sf::Texture texture,int ATK,sf::Vector2<float> direction=sf::Vector2<float>(0.0,1.0));
        virtual ~Bullet();

        int ATK=10;
    protected:
    private:

        double speed=2.0;//初始子弹速度
        sf::Texture texture;

};

#endif // BULLET_H
