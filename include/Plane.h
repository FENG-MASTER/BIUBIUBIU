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

        void fire();//����
        void move(char direction);//�ƶ����� ֧���ĸ�����





    protected:
    private:
        Sky* ownSky;
        int speed=5;

        sf::Texture texture;  //�ɻ�����
};

#endif // PLANE_H
