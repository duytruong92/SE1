#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <stdlib.h>
#include "SFML/Graphics.hpp"

class card
{
public:
    card(){};
	card(int x, int y,int value, int type);
	sf::Sprite return_spi();
    sf::Sprite return_spi_dealer(int times);
    sf::Texture return_tex();
    std::string name1(){return name;};
private:
	sf::Vector2f position;
	sf::Texture tex;
    sf::Sprite  spi;
    std::string name;
    int value; int type;
};

using namespace std;
class data 
{
public:
        data();
        void reload();
        void change_value(int x, int y);
        int get_value(int x, int y);
protected:
        int **Card_play;

};

#endif
