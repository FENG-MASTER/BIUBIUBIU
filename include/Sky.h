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

        sf::RenderWindow *window;//��յĴ���
        Player *player;//��ҷɻ�
        void addBullet(Bullet* bullet);//����ӵ���sky
        void moveBullet();//�ӵ��ƶ�
        void clearBullet();//�Խ����ӵ����л��մ���
        void createEnemies();//������ɵл�

        bool enemyNeedToBeclear(Enemy *enemy);






    protected:
    private:
        sf::Texture texture=GTexture::SKY;//�������
        sf::Font font;//��ʾ����
        sf::Text Score;


        unordered_set<Enemy * > planes;
        unordered_set<Bullet * > bullets;




};

#endif // SKY_H
