
#include "player.hpp"

player :: player()
{
        total_score=0;
        total_score2=0;
        total_money=1000;
        bet_money=0;
}

player :: player ( int x, int y)
{
	pos_x = x;
	pos_y = y;
	total_score=0;
    total_score2=0;
	times=0;
	total_money =1000;
	bet_money = 0;
}

void player::win_money(int x)
{
        total_money = total_money + 2*x;
}

void player::get_bet(int x)
{
        bet_money = x;
        total_money = total_money -x;
}

void player::get_score(int x)
{
    total_score += x;
    total_score2 += x;
} 

void player::get_score(int x, int y)
{
    total_score += x;
    total_score2 +=y;
}

int player::show_money()
{
    return total_money;
}

int player:: show_score()
{
    if(total_score2 > total_score && total_score2<=21 )
    return total_score2;
    return total_score;
}

int player::show_bet()
{
        return bet_money;
}

void player::get_position(int x, int y)
{
        pos_x =x;
}

int player::show_x()
{
        return pos_x;
}

int player::show_y()
{
        return pos_y;
}

void player::reset_point()
{
	bet_money = 0;
	total_score = 0;
    total_score2 = 0;
	times = 0;
    hold_card.reload();
	while(!Card.empty())
	Card.pop_front();
	
}



void player::hit()
{
	int x,y;
	int i = rand()%12;
	int j = rand()%4;
    while(hold_card.get_value(i,j) == 0)
    {
        i = rand()%12;
        j = rand()%4;
    }
	x= pos_x;
	y= pos_y+times*80;
    if(i != 0)
    {
        get_score(hold_card.get_value(i,j));
        hold_card.change_value(i,j);
    }
    
    if(i == 0)
    {
        get_score(1,11);
        hold_card.change_value(i,j);
    }
	card temp(x,y,i,j);
	Card.push_front(temp);
	times++;
}

void player::hit1()
{
	int x,y;
	int i = rand()%12;
	int j = rand()%4;
    while(hold_card.get_value(i,j) == 0)
    {
        i = rand()%12;
        j = rand()%4;
    }
	x= pos_x +times*90;
	y= pos_y;
    if(i != 0)
    {
        get_score(hold_card.get_value(i,j));
         hold_card.change_value(i,j);
    }
    
    if(i == 0)
    {
        get_score(1,11);
        hold_card.change_value(i,j);
    }
	card temp(x,y,i,j);
	Card.push_front(temp);
	times++;
}


list<card> player::get_list()
{
    return Card;
}


void player::draw( sf::RenderWindow *window, list<card> card)
{
    p = card.rbegin();
    
    while(p != card.rend())
    {
        window->draw(p->return_spi());
        p++;
    }
   
 }

void player::draw_dealer( sf::RenderWindow *window,list<card> card )
{
    p = card.rbegin();
    int i =1;
    while(p != card.rend())
    {
        window->draw(p->return_spi_dealer(i));
        p++;
        i++;
    }

}


