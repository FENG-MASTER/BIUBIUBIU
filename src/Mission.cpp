#include "Mission.h"
SMission Mission::listOfMission[8];
Mission::Mission()
{
    //ctor
}

Mission::~Mission()
{
    //dtor
}

void Mission::load(){
//����Ҫ�� ������ �Լ��ɻ��ٶ�  �Լ��ӵ��ٶ� �Լ������ӵ��ٶ� �л��������� �л��ƶ��ٶ� �л�������� �л��ӵ��ٶ�

    listOfMission[0]={0,1,40,15,15,130,2,0.5,13};
    listOfMission[1]={50,1,42,15,14,110,3,0.5,14};
    listOfMission[2]={150,1,43,17,12,100,5,0.8,16};
    listOfMission[3]={200,1,45,18,12,90,6,0.9,18};
    listOfMission[4]={230,2,50,19,12,90,8,1,20};
    listOfMission[5]={250,3,55,19,11,85,9,2,22};
    listOfMission[6]={300,3,56,19,10,81,11,2,22};
    listOfMission[7]={400,4,57,20,10,80,12,2,26};



}
