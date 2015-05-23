#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include<GTexture.h>
#include<Sky.h>
#include<Player.h>
#include<Music.h>
#include<Game.h>
#include<Font.h>
#include<Mission.h>
int main(){
sf::RenderWindow window(sf::VideoMode(600, 800), "BIUBIU  enjoy yourself",sf::Style::Close );

    Music::load();//音乐初始化
    GTexture::load();//纹理初始化
    Font::load();//字体初始化
    Mission::load();//关卡初始化

    Sky sky(&window);
    Player BIU(&sky);
    sky.add(&BIU);
    window.setFramerateLimit(60);
    Game game(&sky);
    game.start();


return EXIT_SUCCESS;
}
