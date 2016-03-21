#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>
#include "SFML/Audio.hpp"
#include "player.hpp"
#include "card.hpp"
using namespace std;
//view
class GameEngine
{
public:
	GameEngine();
	void runGame();
	void handleEvents();
    void play(player* num1 );
    void compare(player num1, player num2, player num3,player dealer, sf::RenderWindow *window);
protected:
	sf::RenderWindow window;
	sf::Event event;
    int check;
    int turn;
};

class position_table : public sf::RectangleShape 
{
public:
	position_table(){};
	position_table(int x, int y)
	{
		setSize(sf::Vector2f(180, 240));
        setFillColor(sf::Color::Green);
        setOutlineColor(sf::Color::White);
        setOutlineThickness(5);
        setPosition(x,y);
	}
    position_table(int x, int y, int r, int d)
    {
        setSize(sf::Vector2f(r, d));
        setFillColor(sf::Color::Green);
        setOutlineColor(sf::Color::White);
        setOutlineThickness(2);
        setPosition(x,y);
    }
private:
	int x;
	int y;
};



//controller

#endif
