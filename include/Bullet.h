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
        void move(char direction);//�ӵ��ƶ�,Ŀǰֻ��ǰ���ͺ���
    protected:
    private:
        double speed=25.0;//��ʼ�ӵ��ٶ�
        sf::Texture texture;

};

#endif // BULLET_H
