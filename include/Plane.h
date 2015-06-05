#ifndef PLANE_H
#define PLANE_H
#include <SFML/Graphics.hpp>
#include<GTexture.h>
#include <SFML/Audio.hpp>
#include<Music.h>
#include<flyingObject.h>
class Sky;
class Plane:public flyingObject
{
    public:
        Plane(Sky* ownSky);
        virtual ~Plane();

        void setFireSpeed(int speed);
        virtual void fire();//����


    protected:
         Sky* ownSky;

         int fireSpeed=2;
        sf::Texture texture;  //�ɻ�����
        sf::Music &BOOM=Music::SOUND_BOOM; //�ɻ���ը����
        sf::Texture BOOMTEXTURE=GTexture::ENEMY_BOOM1;//�ɻ���ը��ͼ
    private:

};

#endif // PLANE_H
