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
        int num=1;//���������˵���������������״̬��, �жϰ��Ƿ�ﵽ�������˶��ı���
        int *_num;
        sf::Vector2<float> direction;//��ǰ����˶�����


        sf::Texture * textureRand;

};

#endif // ITEM_H
