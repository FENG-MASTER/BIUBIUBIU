#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include<GTexture.h>
#include<Sky.h>
#include<Player.h>
#include<Music.h>
#include<Game.h>
int main(){
sf::RenderWindow window(sf::VideoMode(600, 800), "BIUBIU  enjoy yourself",sf::Style::Close );

Music::load();//���ֳ�ʼ��
GTexture::load();//�����ʼ��

Sky sky(&window);
Player BIU(&sky);
sky.add(&BIU);
window.setFramerateLimit(60);
Game game(&sky);
game.start();
window.close();

return EXIT_SUCCESS;
}
