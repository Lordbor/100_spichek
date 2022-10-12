
#include <SFML/Graphics.hpp>
#include <iostream>
#include <locale.h>
#include <ctime>
#include <cstdlib>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <string>
#include <sstream>


sf::RenderWindow window;
sf::Image image, image2, kucka1, INPUTs, menuplayer, player1, player2;
sf::Texture texture, texture2, tex_kucka1, tex_INPUTs, tex_menuplayer, tex_player1, tex_player2;
sf::Sprite sprite, sprite2, sprite_kucha1, sp_INPUTs, sp_menuplayer, sp_player1, sp_player2;
sf::Font font;
sf::Text text, winner;
int InitialCount = 100;
int Count, Num, Player;
bool Correct;
int menuNum = 0;
int gameNum = 0;
int menuopen = 1;


void menu(sf::RenderWindow & window) 
{
	sf::Texture menuTexture1, menuTexture2, aboutTexture, menuBackground;
	sf::Sprite menu1, menu2, about, menuBg;

	bool isMenu = true;
	int menuNum = 0;

	//ÇÀÃÐÓÇÊÀ ÒÅÊÑÒÓÐ
	menuTexture1.loadFromFile("resources/Knopka.png");
	menuTexture2.loadFromFile("resources/Exit.png");
	aboutTexture.loadFromFile("resources/namr_game.png");
	menuBackground.loadFromFile("resources/fon_menu.png");
	
	// ÎÁÚßÂËÅÍÈÅ ÊÍÎÏÊÈ "ÍÀ×ÒÜ ÈÃÐÓ"
	menu1.setTexture(menuTexture1);
	menu1.setPosition(100, 30);
	menu1.setScale(0.167, 0.167);

	// ÎÁÚßÂËÅÍÈÅ ÊÍÎÏÊÈ "ÂÛÕÎÄ ÈÇ ÈÃÐÛ"
	menu2.setTexture(menuTexture2);
	menu2.setPosition(100, 150);
	menu2.setScale(0.167, 0.167);

	// ÇÀÃÐÓÇÊÀ ÔÎÍÀ ÄËß ÌÅÍÞ
	menuBg.setTexture(menuBackground);
	menuBg.setPosition(0, 0);
	menuBg.setScale(0.167, 0.167);

	while (isMenu)
	{
		menu1.setColor(sf::Color::White);
		menu2.setColor(sf::Color::White);
		menuNum = 0;
		//

		//ÏÐÎÈÑÕÎÄÈÒ ÏÎÄÑÒÂÅÒÊÀ ÏÐÈ ÍÀÂÅÄÅÍÈÅ ÍÀ ÊÍÎÏÊÓ "ÍÀ×ÀÒÜ ÈÃÐÓ"
		if (sf::IntRect(100, 30, 250, 50).contains(sf::Mouse::getPosition(window))) 
		{ 
			menu1.setColor(sf::Color::Blue); 
			menuNum = 1; 
		}

		//ÏÐÎÈÑÕÎÄÈÒ ÏÎÄÑÒÂÅÒÊÀ ÏÐÈ ÍÀÂÅÄÅÍÈÅ ÍÀ ÊÍÎÏÊÓ "ÂÛÕÎÄ"
		if (sf::IntRect(100, 150, 250, 50).contains(sf::Mouse::getPosition(window))) 
		{ 
			menu2.setColor(sf::Color::Blue); 
			menuNum = 2; 
		}

		//ÑÎÁÛÒÈß ÍÀÆÀÒÈß ÍÀ "ËÊÌ"
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (menuNum == 1) {	//ÂÛÊËÞ×ÈÒÜ ÎÊÍÎ Ñ "ÌÅÍÞ" ÄËß ÄÀËÜÍÅÉØÅÃÎ ÇÀÏÓÑÊÀ ÏÐÎÃÐÀÌÌÛ
				isMenu = false;
				window.clear(sf::Color(129, 181, 221));
				menuopen = 0;

			}

			if (menuNum == 2)	//ÂÛÊËÞ×ÈÒÜ ÏÐÎÃÐÀÌÌÓ
			{ 
				window.close(); 

				exit(0);
			}
		}
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
				exit(0);
			}
		}

		
		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.display();
	}
	
}

void game(sf::RenderWindow& window) {
	Player = 1;
	window.clear(sf::Color(129, 181, 221));
	bool isGame = true;
	InitialCount = 100;
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
	font.loadFromFile("resources/Inkulinati-Regular.otf");
	text.setFont(font);
	text.setCharacterSize(28);
	text.setFillColor(sf::Color::Black);
	text.setPosition(320, 100);
	winner.setFont(font);
	winner.setCharacterSize(40);
	winner.setFillColor(sf::Color::Black);
	winner.setPosition(200, 100);

	while (isGame) {
	

		window.clear(sf::Color::Black);
		window.draw(sprite);
		window.draw(sprite_kucha1);
		window.draw(sp_INPUTs);
		window.draw(text);
		
			sf::Event event;

			while (window.pollEvent(event))
			{
			
				if (event.type == sf::Event::Closed) {
					window.close();
					exit(0);
				}
				if (InitialCount > 0 && event.type == sf::Event::MouseButtonReleased)
				{
					if (event.mouseButton.button == sf::Mouse::Left && sf::IntRect(82, 303, 42, 75).contains(sf::Mouse::getPosition(window)))
					{
						if (gameNum == 1 && Player == 1)
						{
							InitialCount = InitialCount - 1;
							Player = 2;
						}
						else
						{
							InitialCount = InitialCount - 1;
							Player = 1;
						}
					}
					if (event.mouseButton.button == sf::Mouse::Left && sf::IntRect(122, 303, 42, 75).contains(sf::Mouse::getPosition(window)))
					{
						if (gameNum == 2 && Player == 1)
						{
							InitialCount = InitialCount - 2;
							Player = 2;
						}
						else
						{
							InitialCount = InitialCount - 2;
							Player = 1;
						}
					}
					if (event.mouseButton.button == sf::Mouse::Left && sf::IntRect(162, 303, 42, 75).contains(sf::Mouse::getPosition(window)))
					{
						if (gameNum == 3 && Player == 1)
						{
							InitialCount = InitialCount - 3;
							Player = 2;
						}
						else
						{
							InitialCount = InitialCount - 3;
							Player = 1;
						}
					}
					if (event.mouseButton.button == sf::Mouse::Left && sf::IntRect(207, 303, 42, 75).contains(sf::Mouse::getPosition(window)))
					{
						if (gameNum == 4 && Player == 1)
						{
							InitialCount = InitialCount - 4;
							Player = 2;
						}
						else
						{
							InitialCount = InitialCount - 4;
							Player = 1;
						}
					}
					if (event.mouseButton.button == sf::Mouse::Left && sf::IntRect(257, 303, 42, 75).contains(sf::Mouse::getPosition(window)))
					{
						if (gameNum == 5 && Player == 1)
						{
							InitialCount = InitialCount - 5;
							Player = 2;
						}
						else
						{
							InitialCount = InitialCount - 5;
							Player = 1;
						}
					}
					if (event.mouseButton.button == sf::Mouse::Left && sf::IntRect(297, 303, 42, 75).contains(sf::Mouse::getPosition(window)))
					{
						if (gameNum == 6 && Player == 1)
						{
							InitialCount = InitialCount - 6;
							Player = 2;
						}
						else
						{
							InitialCount = InitialCount - 6;
							Player = 1;
						}
					}
					if (event.mouseButton.button == sf::Mouse::Left && sf::IntRect(347, 303, 42, 75).contains(sf::Mouse::getPosition(window)))
					{
						if (gameNum == 7 && Player == 1)
						{
							InitialCount = InitialCount - 7;
							Player = 2;
						}
						else
						{
							InitialCount = InitialCount - 7;
							Player = 1;
						}
					}
					if (event.mouseButton.button == sf::Mouse::Left && sf::IntRect(390, 303, 42, 75).contains(sf::Mouse::getPosition(window)))
					{
						if (gameNum == 8 && Player == 1)
						{
							InitialCount = InitialCount - 8;
							Player = 2;
						}
						else
						{
							InitialCount = InitialCount - 8;
							Player = 1;
						}
					}
					if (event.mouseButton.button == sf::Mouse::Left && sf::IntRect(450, 303, 42, 75).contains(sf::Mouse::getPosition(window)))
					{
						if (gameNum == 9 && Player == 1)
						{
							InitialCount = InitialCount - 9;
							Player = 2;
						}
						else
						{
							InitialCount = InitialCount - 9;
							Player = 1;
						}
					}
					if (event.mouseButton.button == sf::Mouse::Left && sf::IntRect(490, 303, 58, 75).contains(sf::Mouse::getPosition(window)))
					{
						if (gameNum == 10 && Player == 1)
						{
							InitialCount = InitialCount - 10;
							Player = 2;
						}
						else
						{
							InitialCount = InitialCount - 10;
							Player = 1;
						}
					}

				}
				text.setString(std::to_string(InitialCount));
			}
			if (sf::IntRect(100, 30, 50, 50).contains(sf::Mouse::getPosition(window))) { gameNum = 1; }


			if (sf::IntRect(82, 303, 42, 75).contains(sf::Mouse::getPosition(window)))
				gameNum = 1;
			if (sf::IntRect(122, 303, 42, 75).contains(sf::Mouse::getPosition(window)))
				gameNum = 2;
			if (sf::IntRect(162, 303, 42, 75).contains(sf::Mouse::getPosition(window)))
				gameNum = 3;
			if (sf::IntRect(207, 303, 42, 75).contains(sf::Mouse::getPosition(window)))
				gameNum = 4;
			if (sf::IntRect(257, 303, 42, 75).contains(sf::Mouse::getPosition(window)))
				gameNum = 5;
			if (sf::IntRect(297, 303, 42, 75).contains(sf::Mouse::getPosition(window)))
				gameNum = 6;
			if (sf::IntRect(347, 303, 42, 75).contains(sf::Mouse::getPosition(window)))
				gameNum = 7;
			if (sf::IntRect(390, 303, 42, 75).contains(sf::Mouse::getPosition(window)))
				gameNum = 8;
			if (sf::IntRect(450, 303, 42, 75).contains(sf::Mouse::getPosition(window)))
				gameNum = 9;
			if (sf::IntRect(490, 303, 58, 75).contains(sf::Mouse::getPosition(window)))
				gameNum = 10;
			if (sf::IntRect(0, 0, 640, 250).contains(sf::Mouse::getPosition(window)))
				gameNum = 11;
			if (Player == 1)
			{
				window.draw(sp_menuplayer);
				window.draw(sp_player1);
				if (InitialCount <= 0)
				{

					winner.setString(L"Ïîáåäèòåëü Èãðîê 2");
					window.draw(sprite);
					window.draw(winner);
					if (gameNum == 11 && event.type == sf::Event::MouseButtonReleased)
					{
						
							isGame = false;
							menuopen = 1;
						
					
					}

				}
			}

			if (Player == 2)
			{
				window.draw(sp_menuplayer);
				window.draw(sp_player2);
				if (InitialCount <= 0)
				{
					winner.setString(L"Ïîáåäèòåëü Èãðîê 1");
					window.draw(sprite);
					window.draw(winner);
					if (gameNum == 11 && event.type == sf::Event::MouseButtonReleased)
					{

						isGame = false;
						menuopen = 1;


					}

				}
			}


			window.display();

		}
	}


int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 400), "Menu");
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		if (menuopen == 1)
		{
			menu(window);//âûçîâ ìåíþ
		}
		if (menuopen == 0)
		{
			game(window);
		}
	}

	return 0;
}