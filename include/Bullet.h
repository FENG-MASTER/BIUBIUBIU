#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include<GTexture.h>
class Bullet:public sf::Sprite
{
    public:
        Bullet(sf::Texture texture);
        virtual ~Bullet();
        void setSpeed(int speed);
        int getSpeed();
        void move(char direction);//子弹移动,目前只有前进和后退
    protected:
    private:
        double speed=25.0;//初始子弹速度
        sf::Texture texture;

};

#endif // BULLET_H
