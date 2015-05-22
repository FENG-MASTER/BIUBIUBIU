#ifndef SKY_H
#define SKY_H
#include <SFML/Graphics.hpp>
#include"GTexture.h"
#include<unordered_set>
#include"Player.h"
#include"Bullet.h"
#include<Enemy.h>
class Player;
using namespace std;

class Sky :public sf::Sprite
{
    public:
        Sky(sf::RenderWindow *window);
        virtual ~Sky();
        void add(Player *Player);
        void refresh();

        sf::RenderWindow *window;//天空的窗口
        Player *player;//玩家飞机
        void addBullet(Bullet* bullet,int flat);//添加子弹到sky
        void moveBullet();//子弹移动
        void clearBullet();//对界外子弹进行回收处理
        void createEnemies();//随机生成敌机

        void enemyRandFire();
        bool isEnd();
        void clearEnemyAndBullet();





    protected:
    private:
        sf::Texture texture=GTexture::SKY;//天空纹理
        sf::Font font;//显示字体
        sf::Text Score;


        unordered_set<Enemy * > planes;
        unordered_set<Bullet * > bullets;
        unordered_set<Bullet * > enemyBullets;




};

#endif // SKY_H
