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
        int num=1;//这个变量简单说是用来处理的运行状态的, 判断啊是否达到换方向运动的变量
        int *_num;
        char direction;//当前随机运动方向

        map<string,int> items;//存该道具所能获得的奖励
        list<sf::Texture> itemsTexture;
        int speed;
        sf::Texture texture;
};

#endif // ITEM_H
