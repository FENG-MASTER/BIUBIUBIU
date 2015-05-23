#ifndef FONT_H
#define FONT_H
#include <SFML/Graphics.hpp>

class Font
{
    public:
        Font();
        virtual ~Font();

        static sf::Font Font_Score;
        static sf::Font Font_DEAD;
        static void load();
    protected:
    private:
};

#endif // FONT_H
