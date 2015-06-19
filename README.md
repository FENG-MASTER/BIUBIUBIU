
----------

# c++打飞机游戏实验报告 

----------

## 实验目的 ##
1.	掌握基本工程开发全过程
2.	了解工程开发要注意的问题
3.	综合运用c++知识
4.	掌握UML的基本概念和使用
5.	掌握工程中抽象的运用


## 实验任务 ##
1. 完成SFML配置，显示“SFML works”
2. 显示一架静止的飞机于屏幕底部
3. 背景音乐
4. 左右键，控制移动飞机
5. 限制左右边界
6. 空格键开炮，显示运动的炮弹
7. 炮弹飞出边界处理
8. 随机产生敌机，并向下运动
9. 敌机飞出边界处理
10. 碰撞处理（敌机与炮弹碰撞）
11. 显示敌机爆炸过程
12. 爆炸声音
13. 计分及显示
14. 敌机炮弹处理
15. 被敌机击中处理（炸毁、3条命）
16. 过关控制（过关需要计分、游戏速度控制）
17. ***加入道具系统**
18. ***两种飞机**
19. ***好看的游戏启动画面**
20. ***加入BOSS**
21. **BOOS神奇的轨道和攻击方式**


## 面向用户 ##
本游戏面向喜欢单机游戏的玩家们

## 游戏功能 ##
一般射击类游戏的基本用户体验

## 游戏规则 ##
1. 按键操作: 方向键控制移动  空格开炮  死后F1重新开始
2. 初始生命数:3
3. 一共8个关卡,难度依次提升
4. 过关后敌机难度提升,相应玩家速度提升,加快游戏节奏 
5. 敌机随机生成
6. 敌机随机发射子弹
7. 敌机随机移动
8. 有物品掉落系统,暂时只有生命道具和攻击力道具

## 所用工具 ##
1. codeblocks编译器
2. 第三方库:**SFML**:Simple and Fast Multimedia Library
3. UML建模软件:IBM rational rose
4. Makedown编辑器:MarkdownPad 2

## 前期配置开发环境 ##
参照SFML官网说明配置


----------

# 实战 #

----------

## 模块划分 ##
按照逻辑划分:

1. Sky
2. Game
3. Plane
4. Player
5. Enemy
6. Item
7. Bullet
8. Font
9. Music
10. Mission
11. GTexture
12. flyingObject


## UML图 ##

![](http://image17-c.poco.cn/mypoco/myphoto/20150609/22/6645048120150609224942024.png?1024x609_120)


## 详细类说明 ##
1. Sky类:该类处理大部分游戏核心代码,包括边界处理和碰撞判定等
2. Game类:消息循环所在,用于总控Sky
3. Plane类:抽象出的类,用于给Player类和Enemy类继承
4. Player类:[继承Plane]玩家控制的飞机
5. Enemy类:[继承Plane]敌机类,里面有随机移动和随机发射函数等
6. Item类:道具类
7. Bullet类:子弹类
8. Font类:用于统一管理游戏用到的字体
9. Music类:用于统一管理游戏用到的音效
10. GTexture类:用于统一管理游戏用到纹理
11. Mission类:用于储存游戏关卡信息
12. flyingObject类:给其他飞行物继承用,有move方法和speed属性相关函数


## 关键代码 ##

**子弹碰撞检测代码**:


            for(auto sprite = this->bullets.begin(); sprite!=(this->bullets.end());){
                if((*enemy)->getGlobalBounds().intersects((*sprite)->getGlobalBounds())&&(((*enemy)->health-=(*sprite)->ATK)<0)){
                        (*enemy)->state=1;
                        this->player->addScore((*enemy)->getScore());
                        createItems((*enemy)->getPosition().x,(*enemy)->getPosition().y);


                        this->bullets.erase(sprite);//子弹消失


                        break;

                }
                sprite++;


        }




----------

**位置随机移动函数**(解决由于快速取随机数导致左右频繁移动出现的闪屏现象):
    void Enemy::moveRand(){



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

            }//此处需要把敌机向下移动比率调高,所以简单采取三个S的写法

            this->move(direction);
            num++;
        }else{
            num++;
            this->move(direction);

            if(num>=((*_num)%100)){
                _num =new int;   //此处是一种暴力取随机数方式
                num=1;

            }

        }}



----------

**检查关卡函数:**
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




----------

**Game类最核心业务代码:**

此部分实现了一个效果不错的启动画面,效果图看后面

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



----------
**边界处理函数(这个是物品的边界处理)**:

    void Sky::itemMoveAndCheak(){

    for(auto &item : this->items){
        item->moveRand();
        if(item->getGlobalBounds().intersects(this->player->getGlobalBounds())){
            //吃到道具

                if(item->getFlat==0){
                    item->getSomething(this);

                }

                    if(item->showItemIcon()){
                        delete item;
                        this->items.erase(item);
                        break;

                    }




        }
            //处理物品边界问题

        if(item->getPosition().x>580){
                item->setPosition(5,item->getPosition().y);

        }else if(item->getPosition().x<0){
                item->setPosition(570,item->getPosition().y);
        }


    }
	}




----------
## 游戏截图 ##

**游戏启动画面[动态]:**

![](http://image17-c.poco.cn/mypoco/myphoto/20150605/19/6645048120150605193527046.png?614x834_130)


**游戏画面:**

![](http://image17-c.poco.cn/mypoco/myphoto/20150605/19/6645048120150605193617028.png?606x826_130)

![](http://image17-c.poco.cn/mypoco/myphoto/20150605/19/6645048120150605193707087.png?606x826_130)

![](http://image17-c.poco.cn/mypoco/myphoto/20150618/22/6645048120150618222437095.png?606x826_130)


**游戏失败画面:**

![](http://image17-c.poco.cn/mypoco/myphoto/20150605/19/6645048120150605194343057.png?606x826_130)




----------
## 当前测试情况 ##

未发现BUG

关卡参数有待测试后更改

## 玩家体验与评价 ##


**1.某玩家-二斐**

游戏画面精致，我军飞机十分可爱，BGM好评，感觉是一个十分考验耐心的游戏，是个很快死掉但是又很想接着玩的游戏。但是我军战机和敌军战机死掉的音效是一样的，容易让人分不清呀，我军战机的初始功能也有点弱，分分钟就死掉了呀，爆出的属性加成除了加生命值没有别的是非常有用的呀，都有点鸡肋，希望这个可以加强一下，总这么弱，谁还有信心玩呀。总之，就是一个很好玩的游戏拉。
建议:属性加成那个也可以改改,初始性能也加强一下

**2.某玩家-XX**
前期发给我的几个版本出了很多问题,后来都解决了,可以进入游戏了.
画面看起来不错,不过游戏的难度的设置上有点不尽人意,还有就是那个道具系统,应该是初期版本的原因,道具类型有点少,还有希望能加入大招,增加游戏性,还有就是,居然没有按键说明!!你一定是在逗我,其他的都不错,可以满足了基本游戏需求,BGM劲爆.


其他有待更新

## 可改进地方 ##

1. 设计中的子弹和道具类应该采用 策略模式 ,增强游戏的可拓展性,和维护性.
2. GTexture,MUSIC,MISSION,FONT类应该统一采用单例模式,确保游戏中这些对象的单一性
3. 加入按键说明(已经解决)
4. 游戏窗口大小不可调整(已经修改)
4. 修改游戏难度梯度问题