#include "GameEngine.hpp"
#include <sstream>
#define DEF_WIDTH 1200
#define DEF_HEIGHT 900

GameEngine::GameEngine()
{
	window.create(sf::VideoMode(DEF_WIDTH,DEF_HEIGHT),"BlackJack");

}
//view
void GameEngine::runGame()
{
	int x=0;
	int y=0;
    turn =0;
	player num1(10,300);
    player num2(500,580);
    player num3(1010,300);
    player dealer(500,30);
    
    
    
	while(window.isOpen())
	{
        sf::Vector2i position = sf::Mouse::getPosition();
		window.clear(sf::Color::Green);

		sf::Font font;
		if(!font.loadFromFile("arial.ttf"))
			exit(1);
		sf::Text text("BlackJack", font, 50);
		text.setPosition(10,10);
		text.setColor(sf::Color::Red);

		sf::Text text2("Hit", font, 50);
		text2.setPosition(1070,40);
		text2.setColor(sf::Color::Blue);

        
		sf::Text text3("Hold", font, 50);
		text3.setPosition(1050,120);
		text3.setColor(sf::Color::Blue);

        std::string money;
        money = "Player 1 Total score: ";
        std::stringstream convert;
        convert << num1.show_score();
        money += convert.str();
		sf::Text text1(money, font, 25);
		text1.setPosition(10,250);
		text1.setColor(sf::Color::Red);
         window.draw(text1);

        std::string money1;
        money1 = "Player 3 Total score: ";
        std::stringstream convert1;
        convert1 << num3.show_score();
        money1 += convert1.str();
		sf::Text text5(money1, font, 25);
		text5.setPosition(920,260);
		text5.setColor(sf::Color::Red);
         window.draw(text5);
       
        
        std::string money2;
        money2 = "Player 2 Total score: ";
        std::stringstream convert2;
        convert2 << num2.show_score();
        money2 += convert2.str();
		sf::Text text4(money2, font, 25);
		text4.setPosition(500,550);
		text4.setColor(sf::Color::Red);
        window.draw(text4);


		sf::Texture texture;
		if(!texture.loadFromFile("backside3.jpg"))
			exit(1);
		sf::Sprite sprite(texture);
		sprite.setPosition(500,300);

		position_table rectangle(10,300);
		position_table rectangle1(1010,300);
		position_table rectangle2(500,30);
        position_table rectangle3(500,580);
        position_table rectangle4(1010,30,180,180);
        position_table rectangle5(1020,50,160,50);
        position_table rectangle6(1020,130,160,50);
        if(turn ==0)
        {
            for(int i =0 ;i<2;i++)
            {
                num1.hit();
                num2.hit1();
                num3.hit();
                dealer.hit1();
            }
            turn++;
        }
        else if(turn == 1)
        {
        play(&num1);
        }
        else if(turn == 2)
        {
        play(&num2);
        }
        else if(turn == 3)
        {
        play(&num3);
        }
        else if(turn == 4 && dealer.show_score()<=16)
        {
            dealer.hit1();
        }
        else if(turn == 4 && dealer.show_score()>=17)
        {
            turn++;
            
        }
        
        
        
		handleEvents();
		window.draw(text);
		window.draw(sprite);
		window.draw(rectangle);
		window.draw(rectangle1);
		window.draw(rectangle2);
		window.draw(rectangle3);
        window.draw(rectangle4);
        window.draw(rectangle5);
        window.draw(rectangle6);
        window.draw(text2);
        window.draw(text3);
        
        num1.draw(&window, num1.get_list());
        num2.draw(&window, num2.get_list());
        num3.draw(&window, num3.get_list());
        if(turn < 4)
        {
            dealer.draw_dealer(&window, dealer.get_list());
        }
        else
        {
            dealer.draw(&window, dealer.get_list());
        }
        if(turn == 5)
        {
            compare(num1,num2,num3,dealer,&window);
        }
        if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            check = 1;
        }
        if(turn == 5 && position.x>=565 &&position.x<=745 && position.y >=345 && position.y <=585 && sf::Mouse::isButtonPressed(sf::Mouse::Left) && check == 1 )
        {
            num1.reset_point();
            num2.reset_point();
            num3.reset_point();
            dealer.reset_point();
            turn = 0;
        }

		window.display();
		window.clear();
	}
    
}

//control
void GameEngine::play(player* num1 )
{
   sf::Vector2i position = sf::Mouse::getPosition();
//player1
    if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        check = 1;
    }
    if(position.x>=1085 &&position.x<=1245 && position.y >=100 && position.y <=150 && sf::Mouse::isButtonPressed(sf::Mouse::Left) && check == 1 ) //(1335 , 1500 , 75 , 130)
    {
        if(turn ==2 || turn ==4)
            num1->hit1();
        else
            num1->hit();
        check = 0;
    }
    if(position.x>=1085 && position.x<=1245 && position.y >=175 && position.y <=225 && sf::Mouse::isButtonPressed(sf::Mouse::Left) && check == 1 || num1->show_score()==21)
    {
    turn= turn + 1;
    check =0;    
    }
}

void GameEngine::compare(player num1, player num2, player num3, player dealer, sf::RenderWindow* window)
{

    sf::Font font;
	if(!font.loadFromFile("arial.ttf"))
		exit(1);

    if( num1.show_score() > 21 && dealer.show_score() >21)
    {
        sf::Text text("DRAW", font, 100);
        text.setPosition(10,320);
        text.setColor(sf::Color::Blue);
        window->draw(text);
    }
    else if(num1.show_score() == dealer.show_score() )
    {
        sf::Text text("DRAW", font, 100);
        text.setPosition(10,320);
        text.setColor(sf::Color::Blue);
        window->draw(text);

    }
    else if(num1.show_score() > dealer.show_score() && num1.show_score() <=21)
    {
        sf::Text text("WIN", font, 100);
        text.setPosition(10,320);
        text.setColor(sf::Color::Blue);
        window->draw(text);

    }
    else if( num1.show_score() < dealer.show_score() && dealer.show_score() <=21)
    {
        sf::Text text("LOSE", font,100);
        text.setPosition(10,320);
        text.setColor(sf::Color::Blue);
        window->draw(text);

    }
    else if( num1.show_score() > 21&& dealer.show_score() <=21)
    {
        sf::Text text("LOSE", font, 100);
        text.setPosition(10,320);
        text.setColor(sf::Color::Blue);
        window->draw(text);

    }
    else if( num1.show_score()<= 21 && dealer.show_score() >21)
    {
        sf::Text text("WIN", font, 100);
        text.setPosition(10,320);
        text.setColor(sf::Color::Blue);
        window->draw(text);

    }

    if( num2.show_score() > 21 && dealer.show_score() >21)
    {
        sf::Text text1("DRAW", font,100);
        text1.setPosition(500,600);
        text1.setColor(sf::Color::Blue);
        window->draw(text1);

    }
    else if(num2.show_score() == dealer.show_score() )
    {
        sf::Text text1("DRAW", font,100);
        text1.setPosition(500,600);
        text1.setColor(sf::Color::Blue);
        window->draw(text1);

    }
    else if(num2.show_score() > dealer.show_score() && num2.show_score() <=21)
    {
        sf::Text text1("WIN", font, 100);
        text1.setPosition(500,600);
        text1.setColor(sf::Color::Blue);
        window->draw(text1);

    }
    else if( num2.show_score() < dealer.show_score() && dealer.show_score() <=21)
    {
        sf::Text text1("LOSE", font, 100);
        text1.setPosition(500,600);
        text1.setColor(sf::Color::Blue);
        window->draw(text1);

    }
    else if( num2.show_score() > 21&& dealer.show_score() <=21)
    {
        sf::Text text1("LOSE", font,100);
        text1.setPosition(500,600);
        text1.setColor(sf::Color::Blue);
        window->draw(text1);

    }
    else if( num2.show_score()<= 21 && dealer.show_score() >21)
    {
        sf::Text text1("WIN", font, 100);
        text1.setPosition(500,600);
        text1.setColor(sf::Color::Blue);
        window->draw(text1);

    }

     if( num3.show_score() > 21 && dealer.show_score() >21)
    {
        sf::Text text2("DRAW", font, 100);
        text2.setPosition(980,320);
        text2.setColor(sf::Color::Blue);
        window->draw(text2);

    }
    else if(num3.show_score() == dealer.show_score() )
    {
        sf::Text text2("DRAW", font, 100);
        text2.setPosition(980,320);
        text2.setColor(sf::Color::Blue);
        window->draw(text2);

    }
    else if(num3.show_score() > dealer.show_score() && num3.show_score() <=21)
    {
        sf::Text text2("WIN", font, 100);
        text2.setPosition(980,320);
        text2.setColor(sf::Color::Blue);
        window->draw(text2);

    }
    else if( num3.show_score() < dealer.show_score() && dealer.show_score() <=21)
    {
        sf::Text text2("LOSE", font, 100);
        text2.setPosition(980,320);
        text2.setColor(sf::Color::Blue);
        window->draw(text2);

    }
    else if( num3.show_score() > 21&& dealer.show_score() <=21)
    {
        sf::Text text2("LOSE", font, 100);
        text2.setPosition(980,320);
        text2.setColor(sf::Color::Blue);
        window->draw(text2);

    }
    else if( num3.show_score()<= 21 && dealer.show_score() >21)
    {
        sf::Text text2("WIN", font, 100);
        text2.setPosition(980,300);
        text2.setColor(sf::Color::Blue);
        window->draw(text2);

    }

        sf::Text text3("Play", font, 100);
        text3.setPosition(500,300);
        text3.setColor(sf::Color::Blue);
        window->draw(text3);
}

void GameEngine::handleEvents()
{
	while(window.pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
			window.close();
	}
}




