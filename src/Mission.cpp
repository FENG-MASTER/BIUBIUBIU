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
//分数要求 加命数 自己飞机速度  自己子弹速度 自己发射子弹速度 敌机产生概率 敌机移动速度 敌机发射概率 敌机子弹速度

    listOfMission[0]={0,0,0,10,30,140,1,0.2,4};
    listOfMission[1]={300,1,0,12,28,130,2,0.5,5};
    listOfMission[2]={500,1,0,13,26,120,2,0.8,6};
    listOfMission[3]={700,1,1,14,23,100,3,0.9,8};
    listOfMission[4]={1000,2,1,15,20,90,5,1,10};
    listOfMission[5]={1500,3,2,16,18,85,7,2,12};
    listOfMission[6]={2000,3,0,19,15,81,9,2,15};
    listOfMission[7]={2900,4,0,20,12,80,12,2,16};



}
