#include "Item.h"
#include<GTexture.h>
#include<iostream>
Item::Item(int x,int y)
{
    this->speed=1;
    this->setPosition(x,y);
    items.insert(pair<string, int> ("life",1));
    items.insert(pair<string, int> ("speed",1));
    _num =new int;
    this->setTexture(GTexture::ITEM_HEALTH);



    //ctor
}

Item::~Item()
{
    //dtor
}
void Item::move(char direction){

    if(direction=='A'||direction=='a'){
        this->setPosition(this->getPosition().x-this->speed,this->getPosition().y);

    }else if(direction=='D'||direction=='d'){
        this->setPosition(this->getPosition().x+this->speed,this->getPosition().y);
    }else if(direction=='S'||direction=='s'){
        this->setPosition(this->getPosition().x,this->getPosition().y+this->speed);

    }else if(direction=='W'||direction=='w'){
        this->setPosition(this->getPosition().x,this->getPosition().y-this->speed);

    }


}

map<string ,int > Item::getFuncs(){
    return this->items;


}


void Item::moveRand(){





        if((*_num)<0){(*_num)=-(*_num);}//这里必须为正数,否则会出现飞机不懂的现象


        if(num==1){
            int *ren=new int;


            switch((*ren)%5){

            case 0:
                direction='D';
                break;
            case 1:
                direction='A';
                 break;
            case 2:
                direction='S';
                break;
            case 3:
                direction='S';
                break;
            case 4:
                direction='S';
                break;

            }

            this->move(direction);
            num++;
        }else{
            num++;
            this->move(direction);

            if(num>=((*_num)%100)){
                _num =new int;
                num=1;

            }



        }


}


void Item::setSpeed(int speed){
    this->speed=speed;

}
