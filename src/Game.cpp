#include "Game.h"
#include <SFML/Audio.hpp>
#include<string.h>
#include<iostream>
#define START_X 200
#define START_Y 680
#include<Font.h>
#include<Mission.h>


Game::Game(Sky *sky)
{
    this->sky=sky;
    Score.setColor(sf::Color::Red);
    GameOver_Text.setColor(sf::Color::Green);
    this->Score.setFont(Font::Font_Score);
    GameOver_Text.setFont(Font::Font_DEAD);
    GameOver_Text.setScale(1.2,1.2);
    GameOver_Text.setPosition(this->sky->getGlobalBounds().height/10.0,this->sky->getGlobalBounds().height/3.0);
    this->lifeRemain=this->sky->player->lifeTime;

        this->sky->window->setIcon(GTexture::ICO.getSize().x, GTexture::ICO.getSize().y, GTexture::ICO.getPixelsPtr());


    //ctor
}

Game::~Game()
{
    //dtor
}
void Game::start(){

    this->playMusic();
    while (sky->window->isOpen()){
    //程序最核心代码
	// Process events

	sf::Event event;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
        this->sky->loading=false;
        this->init();
        this->LOAD_BGM.stop();


	}


	if(gameOverFlat==1){

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) {
                    init();//重新开始游戏 F1

                    continue;
                }

            }else if(this->sky->loading==false) {

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    //向左
                    if(this->sky->player->getPosition().x>0){
                        sky->player->move('A');

                    }


                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    //向右

                    if(this->sky->player->getPosition().x<this->sky->getTextureRect().width-170){
                        sky->player->move('D');
                    }
                }



                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ){
                    //向左
                    if(this->sky->player->getPosition().y>0){
                        sky->player->move('W');

                    }


                }


                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ){
                    //向右

                    if(this->sky->player->getPosition().y<(this->sky->window->getSize().y-this->sky->player->getGlobalBounds().height)){
                        sky->player->move('S');
                    }
                }
                if (sf::Keyboard::isKeyPressed( sf::Keyboard::Space)) {
                                this->sky->player->fire();


                    }





            }




	while (sky->window->pollEvent(event)){

            if (event.type == sf::Event::Closed){
                sky->window->close();
                //退出游戏
                return ;
            }






    }

       if(gameOverFlat==1&&waitingForReset==0){

                showGameOver(win);
                waitingForReset=1;

                continue;
        }else if(gameOverFlat==0){

            if(cheakNextMission()==false){
                continue;

            }


                if(sky->isEnd()){


                    if(sky->player->dead()){
                        gameOverFlat=1;
                        stopMusic();
                        sky->player->setPosition(START_X,START_Y);
                        sky->clearEverything();

                        sky->window->clear();
                        continue;
                    }
                    sky->player->setPosition(START_X,START_Y);
                    sky->clearEverything();


                }

                sky->createEnemies();//随机生成敌机
                sky->enemyRandFire();
                sky->moveBullet();//移动所有子弹
                sky->clearBullet();//子弹边界处理
                sky->itemMoveAndCheak();
                 sky->refresh();//刷新显示

                 if(this->sky->loading){
                        sf::Sprite load;
                        load.setTexture(GTexture::LOADING);
                        this->sky->window->draw(load);


                }

                if(!this->sky->loading){


                showInfo();//显示当前分数信息

                }


                // Update the window
                sky->window->display();
            }
    }


}



void Game::playMusic(){

    if(this->sky->loading){
        LOAD_BGM.play();

    }else{
        this->BGM.play();
    }


}

void Game::stopMusic(){
    this->BGM.stop();
}
void Game::showInfo(){
    this->lifeRemain=this->sky->player->lifeTime;
    char str[80];
    sprintf(str,"Mission:%d \nScore:%d \n life:%d",this->MissionOfNow,this->sky->player->getScore(),lifeRemain);
    Score.setString(str);
    this->sky->window->draw(Score);
}

void Game::showGameOver(bool win){

    char str[80];
    if(win){
        sprintf(str,"YOU WIN!!! \n YOUR Score:%d \n Pause F1 to replay",this->sky->player->getScore());

    }else{
        sprintf(str,"YOUR ARE DEAD!!! \n YOUR Score:%d \n Pause F1 to replay",this->sky->player->getScore());
    }

    GameOver_Text.setString(str);
    sky->window->draw(GameOver_Text);
    sky->window->display();


}
void Game::init(){
    gameOverFlat=0;
    waitingForReset=0;
    MissionOfNow=0;
    sky->player->setPosition(START_X,START_Y);
    sky->clearEverything();
    sky->window->clear();
    sky->player->init();
    playMusic();

}
bool Game::cheakNextMission(){



                if(MissionOfNow==Mission::numOfAll-1){
                    win=true;
                    waitingForReset=0;
                    gameOverFlat=1;
                    stopMusic();
                    sky->player->setPosition(START_X,START_Y);
                    sky->clearEverything();
                    sky->window->clear();
                    return false;

                }else{
                    if(this->sky->player->getScore()>=Mission::listOfMission[MissionOfNow].Score){
                            this->sky->player->lifeTime+=(Mission::listOfMission[MissionOfNow].addLife);
                            this->sky->player->setSpeed(this->sky->player->getSpeed()+Mission::listOfMission[MissionOfNow].PlayerSpeed);
                            this->sky->player->setfireDensity(Mission::listOfMission[MissionOfNow].playerFireSpeed);
                            this->sky->player->setFireSpeed(Mission::listOfMission[MissionOfNow].playerDulletSpeed);
                            this->sky->setEnemyCreateRate(Mission::listOfMission[MissionOfNow].enemyCreateRate);
                            this->sky->setEnemySpeed(Mission::listOfMission[MissionOfNow].enemySpeed);
                            this->sky->setEnemyFireRate(Mission::listOfMission[MissionOfNow].enemyFireRate);
                            this->sky->setEnemyBulletSpeed(Mission::listOfMission[MissionOfNow].enemyBulletSpeed);
                            MissionOfNow++;
                            std::cout<<MissionOfNow;

                    }
                }


                return true;

}


