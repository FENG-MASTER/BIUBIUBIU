#ifndef SKY_H
#define SKY_H
#include <SFML/Graphics.hpp>
#include"GTexture.h"
#include<unordered_set>
#include"Player.h"
#include"Bullet.h"
#include<Enemy.h>
#include<Item.h>
#include<Skill.h>
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
        void clearEverything(bool flat);
        void setEnemyCreateRate(int rate);
        void setEnemySpeed(double speed);
        void setEnemyFireRate(double rate);
        void setEnemyBulletSpeed(double speed);
        void createBoss(int level);


        void itemMoveAndCheak();
        bool loading=true;//这个是用于开始画面,表示玩家无敌
        bool bossMission=false;
        int& getScore();
        friend class Skill;

void createItems(int x,int y);


    protected:
    private:


        sf::Texture texture=GTexture::SKY;//天空纹理
        int createRate=100;//越大生成速率越低
        double enemySpeed=2;
        double enemyFireRate=0.5;
        double enemyBulletSpeed=13;



        unordered_set<Enemy * > planes;
        unordered_set<Bullet * > bullets;
        unordered_set<Bullet * > enemyBullets;
        unordered_set<Item * > items;




};

#endif // SKY_H
