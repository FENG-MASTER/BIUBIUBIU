#include "Font.h"
sf::Font Font::Font_Score;
sf::Font Font::Font_DEAD;
Font::Font()
{
    //ctor
}

Font::~Font()
{
    //dtor
}
void Font::load(){
    Font_DEAD.loadFromFile("C:\\Windows\\Fonts\\simsun.ttc");
    Font_Score.loadFromFile("C:\\Windows\\Fonts\\simsun.ttc");


}
