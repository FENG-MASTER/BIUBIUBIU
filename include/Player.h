#ifndef PLAYER_H
#define PLAYER_H
//#include <SFML/Graphics.hpp>
#include "Plane.h"
//#include"GTexture.h"



class Player :public Plane
{
    public:
        Player(Sky* ownSky);
        virtual ~Player();
    protected:
    private:
        sf::Texture texture=GTexture::PLAYER_NORMAL;//Íæ¼Ò·É»úÎÆÀí
};

#endif // PLAYER_H
