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

        virtual void fire();//开火
        void move(char direction);//移动函数 支持四个方向







    protected:
         Sky* ownSky;
    private:

        int speed=5;



        sf::Texture texture;  //飞机纹理
};

#endif // PLANE_H
