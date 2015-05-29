#ifndef ITEM_H
#define ITEM_H
#include<list>
#include<map>
#include <SFML/Graphics.hpp>
using namespace std;
class Item :public sf::Sprite
{
    public:
        Item(int x,int y);
        virtual ~Item();
        void move(char direction);
        map<string ,int > getFuncs();
        void moveRand();
        void setSpeed(int speed);

    protected:
    private:
        int num=1;//���������˵���������������״̬��, �жϰ��Ƿ�ﵽ�������˶��ı���
        int *_num;
        char direction;//��ǰ����˶�����

        map<string,int> items;//��õ������ܻ�õĽ���
        list<sf::Texture> itemsTexture;
        int speed;
        sf::Texture texture;
};

#endif // ITEM_H
