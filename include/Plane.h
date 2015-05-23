#ifndef PLANE_H
#define PLANE_H
#include <SFML/Graphics.hpp>
#include<GTexture.h>
#include <SFML/Audio.hpp>
#include<Music.h>
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
         int speed=5;
         int fireSpeed=2;
        sf::Texture texture;  //飞机纹理
        sf::Music &BOOM=Music::SOUND_BOOM; //飞机爆炸声音
        sf::Texture BOOMTEXTURE=GTexture::ENEMY_BOOM1;//飞机爆炸贴图
    private:

};

#endif // PLANE_H
