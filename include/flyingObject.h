#ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H
#include <SFML/Graphics.hpp>

class flyingObject :public sf::Sprite
{
    public:
        flyingObject();
        virtual ~flyingObject();
        void move(sf::Vector2<float> direction);
        void move();
        void setSpeed(double speed);
        int getSpeed();
    protected:
        sf::Vector2<float> direction; //��������,Ĭ������
        double speed=1;
    private:
};

#endif // FLYINGOBJECT_H
