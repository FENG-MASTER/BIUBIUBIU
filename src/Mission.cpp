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

    listOfMission[0]={0,0,0,15,10,200,1,0.2,4};
    listOfMission[1]={300,1,0,12,1,180,1,0.5,5};
    listOfMission[2]={800,1,0,13,2,170,2,0.8,6};
    listOfMission[3]={1500,1,1,14,2,160,2,0.9,8};
    listOfMission[4]={2000,2,1,15,0,120,3,1,10};
    listOfMission[5]={2500,3,2,16,3,100,5,2,12};
    listOfMission[6]={3000,3,0,19,3,81,7,2,15};
    listOfMission[7]={4000,4,0,20,3,80,9,2,16};



}
