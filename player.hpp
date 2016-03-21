#ifndef PLAYER_H
#define PLAYER_H
#include <list>
#include <iostream>
#include <stdlib.h>
#include "card.hpp"
#include "SFML/Graphics.hpp"


class player
{
public: 
    player();
	player(int x, int y);
    void win_money(int x);
    int show_money();
    void get_score(int x);
    void get_score(int x, int y);
    int show_score();
    void get_bet(int x);
    int show_bet();
    void get_position(int x, int y);
    int show_x();
    int show_y();
	void reset_point();
	void draw( sf::RenderWindow *window,list<card> card );
    void draw_dealer( sf::RenderWindow *window,list<card> card );
	void hit();
    void hit1();
    list<card> get_list();
    sf::Sprite get_draw();
protected:
	int total_score, total_score2;
    int total_money;
    int bet_money;
    int pos_x;
    int pos_y;
	int times;
	sf::Texture table;
	sf::Sprite tab;
	list<card> Card;
    list<card>::reverse_iterator p;
    data hold_card;
};


#endif

