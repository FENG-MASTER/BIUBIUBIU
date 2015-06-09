#ifndef MISSION_H
#define MISSION_H

typedef struct SMission
{
    int Score;
    int addLife;
    int PlayerSpeed;
    int playerDulletSpeed;
    int playerFireSpeed;
    int enemyCreateRate;
    double enemySpeed;
    double enemyFireRate;
    double enemyBulletSpeed;


}SMission;


class Mission
{
    public:
        Mission();
        virtual ~Mission();
        //关卡需要分数  到达关卡送生命数  自己飞机移动速度 自己子弹速度 敌机生成速率 敌机飞机速度 敌机发射子弹概率  敌机子弹速度
      const  static int numOfAll=8;

       static SMission listOfMission[numOfAll];
        static void load();


    protected:
    private:
};

#endif // MISSION_H
