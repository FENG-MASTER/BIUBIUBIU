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

    listOfMission[0]={0,0,10,10,30,140,1,0.2,4};
    listOfMission[1]={100,1,12,12,28,130,2,0.5,5};
    listOfMission[2]={250,1,14,13,26,120,2,0.8,6};
    listOfMission[3]={400,1,15,14,23,100,3,0.9,8};
    listOfMission[4]={550,2,16,15,20,90,5,1,10};
    listOfMission[5]={650,3,17,16,18,85,7,2,12};
    listOfMission[6]={800,3,18,19,15,81,9,2,15};
    listOfMission[7]={1000,4,19,20,12,80,12,2,19};



}
