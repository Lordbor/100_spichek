
#include <SFML/Graphics.hpp>

#include <iostream>
#include <locale.h>
#include <ctime>
#include <cstdlib>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <string>
sf::RenderWindow window;
sf::Image image, image2, kucka1, INPUTs, menuplayer, player1, player2;
sf::Texture texture, texture2, tex_kucka1, tex_INPUTs, tex_menuplayer, tex_player1, tex_player2;
sf::Sprite sprite, sprite2, sprite_kucha1, sp_INPUTs, sp_menuplayer, sp_player1, sp_player2;
sf::Font font;

int InitialCount = 100;
int Count, Num, Player;
bool Correct;
int menuNum = 0;
int gameNum = 0;

void menu(sf::RenderWindow & window) {
	sf::Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuTexture1.loadFromFile("resources/Knopka.png");
	menuTexture3.loadFromFile("resources/Exit.png");
	aboutTexture.loadFromFile("resources/namr_game.png");
	menuBackground.loadFromFile("resources/fon_menu.png");
	sf::Sprite menu1, menu2, menu3, about, menuBg;

	bool isMenu = 1;
	int menuNum = 0;
	menu1.setTexture(menuTexture1);
	menu1.setPosition(100, 30);
	menu1.setScale(0.167, 0.167);
	menu3.setTexture(menuTexture3);
	menu3.setPosition(100, 150);
	menu3.setScale(0.167, 0.167);
	menuBg.setTexture(menuBackground);
	menuBg.setPosition(0, 0);
	menuBg.setScale(0.167, 0.167);
	while (isMenu)
	{
		menu1.setColor(sf::Color::White);
		menu3.setColor(sf::Color::White);
		menuNum = 0;
		window.clear(sf::Color(129, 181, 221));

		if (sf::IntRect(100, 30, 250, 50).contains(sf::Mouse::getPosition(window))) { menu1.setColor(sf::Color::Blue); menuNum = 1; }
		if (sf::IntRect(100, 150, 250, 50).contains(sf::Mouse::getPosition(window))) { menu3.setColor(sf::Color::Blue); menuNum = 3; }

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (menuNum == 1) isMenu = false; //если нажали первую кнопку, то выходим из меню 
			if (menuNum == 3) { window.close(); isMenu = false; }

		}
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);

		window.display();
	}
}
int main()
{

	
	Player = 1;
	sf::RenderWindow window(sf::VideoMode(640, 400), "Kychka-pc.ru 31");
	window.setFramerateLimit(60);
	menu(window);//вызов меню
	image.loadFromFile("resources/fon1.png"); 
	image2.loadFromFile("resources/spichka_1.png");
	kucka1.loadFromFile("resources/kucha1.png");
	texture.loadFromImage(image);
	texture2.loadFromImage(image2);
	tex_kucka1.loadFromImage(kucka1);
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
	sprite.setScale(0.167, 0.167);
	sprite2.setTexture(texture2);
	sprite2.setPosition(50, 50);
	sprite_kucha1.setTexture(tex_kucka1);
	sprite_kucha1.setPosition(270, 150);
	sprite_kucha1.setScale(0.167, 0.167);
	INPUTs.loadFromFile("resources/INPUT.png");
	tex_INPUTs.loadFromImage(INPUTs);
	sp_INPUTs.setTexture(tex_INPUTs);
	sp_INPUTs.setPosition(70, 300);
	sp_INPUTs.setScale(0.167, 0.167);
	menuplayer.loadFromFile("resources/bumplayer.png");
	tex_menuplayer.loadFromImage(menuplayer);
	sp_menuplayer.setTexture(tex_menuplayer);
	sp_menuplayer.setPosition(70, 70);
	sp_menuplayer.setScale(0.167, 0.167);
	player1.loadFromFile("resources/player1.png");
	tex_player1.loadFromImage(player1);
	sp_player1.setTexture(tex_player1);
	sp_player1.setPosition(80, 80);
	sp_player1.setScale(0.167, 0.167);
	player2.loadFromFile("resources/player2.png");
	tex_player2.loadFromImage(player2);
	sp_player2.setTexture(tex_player2);
	sp_player2.setPosition(80, 80);
	sp_player2.setScale(0.167, 0.167);
	/*font.loadFromFile("resources/Inkulinati-Regular.otf");
	Start_game.setFont(font);*/


	std::string str;
	sf::String text;

	while (window.isOpen())
	{
		
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

				if (event.type == sf::Event::MouseButtonReleased)
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						if (gameNum == 1 && Player == 1) {
							InitialCount = InitialCount - 1;
							Player = 2;

						}
						else
						{
							InitialCount = InitialCount - 1;
							Player = 1;
						}
					}


				}
			
		}

		


		window.clear(sf::Color::Black);
		window.draw(sprite);
		window.draw(sprite_kucha1);
		window.draw(sp_INPUTs);
		if (sf::IntRect(100, 30, 50, 50).contains(sf::Mouse::getPosition(window))) { gameNum = 1; }

		if (Player == 1) {
			window.draw(sp_menuplayer);
			window.draw(sp_player1);

		}
		if (Player == 2) {
			window.draw(sp_menuplayer);
			window.draw(sp_player2);

		}
	

		
		
	


	
		window.display();
	} 
	return 0;
}



	

	