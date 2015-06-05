#ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H
#include <SFML/Graphics.hpp>

class flyingObject :public sf::Sprite
{
    public:
        flyingObject();
        virtual ~flyingObject();
        void move(char direction);
        void setSpeed(int speed);
        int getSpeed();
    protected:
        int speed=5;
    private:
};

#endif // FLYINGOBJECT_H
