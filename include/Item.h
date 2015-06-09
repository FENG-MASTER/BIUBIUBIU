#ifndef ITEM_H
#define ITEM_H
#include<list>
#include<map>
#include <SFML/Graphics.hpp>
#include<flyingObject.h>
class Sky;
using namespace std;
class Item :public flyingObject
{
    public:
        Item(int x,int y);
        virtual ~Item();

        void moveRand();

        sf::Texture * itemsTexture=NULL;
        bool showItemIcon();
        int getFlat=0;
        void getSomething(Sky *sky);
    protected:
    private:
        int num=1;//这个变量简单说是用来处理的运行状态的, 判断啊是否达到换方向运动的变量
        int *_num;
        sf::Vector2<float> direction;//当前随机运动方向


        sf::Texture * textureRand;

};

#endif // ITEM_H
