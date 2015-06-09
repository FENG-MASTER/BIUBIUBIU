#ifndef SKY_H
#define SKY_H
#include <SFML/Graphics.hpp>
#include"GTexture.h"
#include<unordered_set>
#include"Player.h"
#include"Bullet.h"
#include<Enemy.h>
#include<Item.h>
class Player;
using namespace std;

class Sky :public sf::Sprite
{
    public:
        Sky(sf::RenderWindow *window);
        virtual ~Sky();
        void add(Player *Player);
        void refresh();

        sf::RenderWindow *window;//��յĴ���
        Player *player;//��ҷɻ�
        void addBullet(Bullet* bullet,int flat);//����ӵ���sky
        void moveBullet();//�ӵ��ƶ�
        void clearBullet();//�Խ����ӵ����л��մ���
        void createEnemies();//������ɵл�

        void enemyRandFire();
        bool isEnd();
        void clearEverything(bool flat);
        void setEnemyCreateRate(int rate);
        void setEnemySpeed(double speed);
        void setEnemyFireRate(double rate);
        void setEnemyBulletSpeed(double speed);
        void createBoss(int level);


        void itemMoveAndCheak();
        bool loading=true;





    protected:
    private:

        void createItems(int x,int y);
        sf::Texture texture=GTexture::SKY;//�������
        int createRate=100;//Խ����������Խ��
        double enemySpeed=2;
        double enemyFireRate=0.5;
        double enemyBulletSpeed=13;



        unordered_set<Enemy * > planes;
        unordered_set<Bullet * > bullets;
        unordered_set<Bullet * > enemyBullets;
        unordered_set<Item * > items;




};

#endif // SKY_H
