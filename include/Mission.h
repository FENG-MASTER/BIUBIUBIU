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
        //�ؿ���Ҫ����  ����ؿ���������  �Լ��ɻ��ƶ��ٶ� �Լ��ӵ��ٶ� �л��������� �л��ɻ��ٶ� �л������ӵ�����  �л��ӵ��ٶ�
      const  static int numOfAll=8;

       static SMission listOfMission[numOfAll];
        static void load();


    protected:
    private:
};

#endif // MISSION_H
