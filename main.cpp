
#include <SFML/Graphics.hpp>
#include <iostream>
#include <locale.h>
#include <ctime>
#include <cstdlib>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

sf::RenderWindow window;
sf::Image image;
sf::Texture texture;
sf::Sprite sprite;
sf::Image image2;
sf::Texture texture2;
sf::Sprite sprite2;
sf::Font font;
sf::Text Start_game;

const int InitialCount = 100;
int Count, Num, Player;
bool Correct;
int menuNum = 0;

void menu(sf::RenderWindow & window) {
	sf::Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuTexture1.loadFromFile("resources/Knopka.png");
	menuTexture3.loadFromFile("resources/spichka_5.png");
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

		if (sf::IntRect(100, 30, 300, 50).contains(sf::Mouse::getPosition(window))) { menu1.setColor(sf::Color::Blue); menuNum = 1; }
		if (sf::IntRect(100, 150, 300, 50).contains(sf::Mouse::getPosition(window))) { menu3.setColor(sf::Color::Blue); menuNum = 3; }

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


	
	sf::RenderWindow window(sf::VideoMode(640, 400), "Kychka-pc.ru 31");
	window.setFramerateLimit(60);
	menu(window);//вызов меню
	image.loadFromFile("resources/fon1.png"); 
	image2.loadFromFile("resources/spichka_1.png");
	texture.loadFromImage(image);
	texture2.loadFromImage(image2);
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
	sprite.setScale(0.167, 0.167);
	sprite2.setTexture(texture2);
	sprite2.setPosition(50, 50);
	/*font.loadFromFile("resources/Inkulinati-Regular.otf");
	Start_game.setFont(font);*/




	while (window.isOpen())
	{
		
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}




		window.clear(sf::Color::Black);
		window.draw(sprite);
		window.display();
	


	} 
	return 0;
}

/*int name() {

	
		srand(time(0));
		system("cls");
		Player = 1;
		Count = InitialCount;
		do {

			if (Player == 1) {
				do {
					std::cout << "Ваш ход. На столе " << Count << " спичек.\n";
					std::cout << "Сколько спичек Вы берете?\n";
					std::cin >> Num;
					if (Num >= 1 && Num <= 10 && Num <= Count)
						Correct = true;
					else
					{
						std::cout << "Неверно! Повторите ввод!\n";
						Correct = false;
					}
				} while (!Correct);
			}
			else
			{
				do {
					Num = rand() % 10 + 1;
					if (Num > Count)
						Num = Count;
					std::cout << "Мой ход. Я взял " << Num << " спичек\n";
				} while (!Correct);
			}
			Count -= Num;
			if (Player == 1)
				Player = 2;
			else
				Player = 1;
		} while (Count > 0);
		if (Player == 1)
			std::cout << "Вы победили!";
		else std::cout << "Вы проиграли!";
		return 0;
	
}*/