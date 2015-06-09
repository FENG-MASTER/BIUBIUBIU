#include "Item.h" itemsTexture=&GTexture::ITEM_HEALTH;
#include<GTexture.h>
#include<iostream>
#include<math.h>
#include<time.h>
#include<windows.h>
#include<GTexture.h>
#include<Sky.h>
Item::Item(int x,int y)
{
    this->speed=1;
    this->setPosition(x,y);

    textureRand=&GTexture::ITEM_RAND;
    itemsTexture=textureRand;


    srand(time(NULL));
    int i=abs(rand()%2);
    if(i==0){
        itemsTexture=&GTexture::ITEM_HEALTH;

    }else if(i==1){
        itemsTexture=&GTexture::ITEM_ATK;
    }




    _num =new int;
    this->setTexture(*textureRand);



    //ctor
}

Item::~Item()
{
    //dtor
}





void Item::moveRand(){





        if((*_num)<0){(*_num)=-(*_num);}//这里必须为正数,否则会出现飞机不懂的现象


        if(num==1){
            int *ren=new int;


            switch((*ren)%5){

            case 0:
                direction=sf::Vector2<float>(1.0,0);
                break;
            case 1:
                direction=sf::Vector2<float>(-1.0,0);
                 break;
            case 2:
                direction=sf::Vector2<float>(0,1);
                break;
            case 3:
                direction=sf::Vector2<float>(0,1);
                break;
            case 4:
                direction=sf::Vector2<float>(0,1);
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



bool Item::showItemIcon(){
    if(getFlat!=8){
        this->setTexture(*itemsTexture);
        getFlat++;
        return false;

    }else{
        return true;


    }


}
void Item::getSomething(Sky *sky){
    if(this->itemsTexture==&GTexture::ITEM_HEALTH){
            sky->player->lifeTime++;


    }else if(itemsTexture==&GTexture::ITEM_ATK){
            sky->player->ATK+=2;

    }





}
