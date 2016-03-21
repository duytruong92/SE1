#include "card.hpp"
#include <string>

card::card (int x, int y, int value, int type)
{
    name;
	position.x = x;
	position.y = y;
    this->value = value;
    this->type = type;
    switch(value)
    {   
        case 0:
        switch(type)
        {        
        case 0:
            name = "Ace_Of_Spades_clip_art_medium.png";
		break;
        case 1:
            name = "Ace_Of_Clubs_clip_art_medium.png";
        break;
        case 2:
            name = "Ace_Of_Diamonds_clip_art_medium.png";
        break;
        case 3:
            name = "Ace_Of_Hearts_clip_art_medium.png";
        break;
        }
        break;

        case 1:
        switch(type)
        {        
        case 0:
            name = "Two_Of_Spades_clip_art_medium.png";
		break;
        case 1:
            name = "Two_Of_Clubs_clip_art_medium.png";
        break;
        case 2:
            name = "Two_Of_Diamonds_clip_art_medium.png";
        break;
        case 3:
            name = "Two_Of_Hearts_clip_art_medium.png";
        break;
        }
        break;

        case 2:
        switch(type)
        {        
        case 0:
            name = "Three_Of_Spades_clip_art_medium.png";
		break;
        case 1:
            name = "Three_Of_Clubs_clip_art_medium.png";
        break;
        case 2:
            name = "Three_Of_Diamonds_clip_art_medium.png";
        break;
        case 3:
            name = "Three_Of_Hearts_clip_art_medium.png";
        break;
        }
        break;

        case 3:
        switch(type)
        {        
        case 0:
            name = "Four_Of_Spades_clip_art_medium.png";
		break;
        case 1:
            name = "Four_Of_Clubs_clip_art_medium.png";
        break;
        case 2:
            name = "Four_Of_Diamonds_clip_art_medium.png";
        break;
        case 3:
            name = "Four_Of_Hearts_clip_art_medium.png";
        break;
        }
        break;

        case 4:
        switch(type)
        {        
        case 0:
            name = "Five_Of_Spades_clip_art_medium.png";
		break;
        case 1:
            name = "Five_Of_Clubs_clip_art_medium.png";
        break;
        case 2:
            name = "Five_Of_Diamonds_clip_art_medium.png";
        break;
        case 3:
            name = "Five_Of_Hearts_clip_art_medium.png";
        break;
        }
        break;

        case 5:
        switch(type)
        {        
        case 0:
            name = "Six_Of_Spades_clip_art_medium.png";
		break;
        case 1:
            name = "Six_Of_Clubs_clip_art_medium.png";
        break;
        case 2:
            name = "Six_Of_Diamonds_clip_art_medium.png";
        break;
        case 3:
            name = "Six_Of_Hearts_clip_art_medium.png";
        break;
        }
        break;

        case 6:
        switch(type)
        {        
        case 0:
            name = "Seven_Of_Spades_clip_art_medium.png";
		break;
        case 1:
            name = "Seven_Of_Clubs_clip_art_medium.png";
        break;
        case 2:
            name = "Seven_Of_Diamonds_clip_art_medium.png";
        break;
        case 3:
            name = "Seven_Of_Hearts_clip_art_medium.png";
        break;
        }
        break;

        case 7:
        switch(type)
        {        
        case 0:
            name = "Eight_Of_Spades_clip_art_medium.png";
		break;
        case 1:
            name = "Eight_Of_Clubs_clip_art_medium.png";
        break;
        case 2:
            name = "Eight_Of_Diamonds_clip_art_medium.png";
        break;
        case 3:
            name = "Eight_Of_Hearts_clip_art_medium.png";
        break;
        }
        break;

        case 8:
        switch(type)
        {        
        case 0:
            name = "Nine_Of_Spades_clip_art_medium.png";
		break;
        case 1:
            name = "Nine_Of_Clubs_clip_art_medium.png";
        break;
        case 2:
            name = "Nine_Of_Diamonds_clip_art_medium.png";
        break;
        case 3:
            name = "Nine_Of_Hearts_clip_art_medium.png";
        break;
        }
        break;

        case 9:
        switch(type)
        {        
        case 0:
            name = "Ten_Of_Spades_clip_art_medium.png";
		break;
        case 1:
            name = "Ten_Of_Clubs_clip_art_medium.png";
        break;
        case 2:
            name = "Ten_Of_Diamonds_clip_art_medium.png";
        break;
        case 3:
            name = "Ten_Of_Hearts_clip_art_medium.png";
        break;
        }
        break;

        case 10:
        switch(type)
        {        
        case 0:
            name = "Jack_Of_Spades_clip_art_medium.png";
		break;
        case 1:
            name = "Jack_Of_Clubs_clip_art_medium.png";
        break;
        case 2:
            name = "Jack_Of_Diamonds_clip_art_medium.png";
        break;
        case 3:
            name = "Jack_Of_Hearts_clip_art_medium.png";
        break;
        }
        break;

        case 11:
        switch(type)
        {        
        case 0:
            name = "Queen_Of_Spades_clip_art_medium.png";
		break;
        case 1:
            name = "Queen_Of_Clubs_clip_art_medium.png";
        break;
        case 2:
            name = "Queen_Of_Diamonds_clip_art_medium.png";
        break;
        case 3:
            name = "Queen_Of_Hearts_clip_art_medium.png";
        break;
        }
        break;

        case 12:
        switch(type)
        {        
        case 0:
            name = "King_Of_Spades_clip_art_medium.png";
		break;
        case 1:
            name = "King_Of_Clubs_clip_art_medium.png";
        break;
        case 2:
            name = "King_Of_Diamonds_clip_art_medium.png";
        break;
        case 3:
            name = "King_Of_Hearts_clip_art_medium.png";
        break;
        }
        break;
	}   
}


sf::Texture card::return_tex()
{
       return tex;
}

sf::Sprite card::return_spi()
{
	tex.loadFromFile(name);
    spi.setTexture(tex);
    spi.setPosition(position.x, position.y);
    spi.scale(sf::Vector2f(0.92f, 0.82f));
    return spi;
}

sf::Sprite card::return_spi_dealer(int times)
{
    string name_temp;
    if(times == 1)
    {
    name_temp = "backside3.jpg";
	tex.loadFromFile(name_temp);
    spi.setTexture(tex);
    spi.setPosition(position.x, position.y);
    return spi;
    }
    else
    {
	tex.loadFromFile(name);
    spi.setTexture(tex);
    spi.setPosition(position.x, position.y);
    spi.scale(sf::Vector2f(0.92f, 0.82f));
    return spi;
    }
}

data :: data()
{
        int i,j;
        Card_play = new int* [13];
        for(i=0;i<13; i++)
                Card_play[i] = new int[4];
        for(i = 0 ; i<13;i++)
        {

                for(j=0;j<4;j++)
                if(i>=9)
                {
                        Card_play[i][j]= 10;
                }
                else
                {
                        Card_play[i][j]=i+1;
                }
        }
}

void data :: reload()
{
        for(int i = 0 ; i<13;i++)
        {
                for(int j=0;j<4;j++)
                if(i>=9)
                {
                        Card_play[i][j]= 10;
                }
                else
                {
                        Card_play[i][j]=i+1;
                }
        }

}

void data::change_value(int x, int y)
{
    Card_play[x][y] = 0;
}
int data::get_value(int x, int y)
{
        return Card_play[x][y];
}

