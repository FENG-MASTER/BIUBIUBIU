#ifndef PLANE_H
#define PLANE_H
#include <SFML/Graphics.hpp>
#include<GTexture.h>
//#include<Sky.h>
class Sky;
class Plane:public sf::Sprite
{
    public:
        Plane(Sky* ownSky);
        virtual ~Plane();
        void setSpeed(int speed);
        virtual void fire();//����
        void move(char direction);//�ƶ����� ֧���ĸ�����

    protected:
         Sky* ownSky;
         int speed=5;
         int fireSpeed=2;
    private:
        sf::Texture texture;  //�ɻ�����
};

#endif // PLANE_H
