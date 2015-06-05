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
        virtual void fire();//¿ª»ð


    protected:
         Sky* ownSky;

         int fireSpeed=2;
        sf::Texture texture;  //·É»úÎÆÀí
        sf::Music &BOOM=Music::SOUND_BOOM; //·É»ú±¬Õ¨ÉùÒô
        sf::Texture BOOMTEXTURE=GTexture::ENEMY_BOOM1;//·É»ú±¬Õ¨ÌùÍ¼
    private:

};

#endif // PLANE_H
