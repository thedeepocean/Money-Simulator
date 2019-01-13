#include <iostream>

#include <string>

#include <vector>

#include <fstream>

#include <ctime>

#include <cmath>

#include <cstdlib>

#include <sstream>

#include <SFML\Graphics.hpp>

#include <SFML\Audio.hpp>



// dont worry just for STR to INT for text
template <typename T>

std::string toString(T arg) {

	std::stringstream ss;

	ss << arg;

	return ss.str();

}



// HOW MUCH YOU UPGRADE (house)

int HMUU = 0;



float moneyWorth = 3.0;


bool stageOneHouse = true;
bool stageTwoHouse = false;


bool defaultClass = true;

bool rookieClass = false;

bool wealthClass = false;

bool richClass = false;

bool proClass = false;

bool eliteClass = false;

bool legendClass = false;

bool millionaireClass = false;



float money = 0.0;



int addMoney() {

	if (defaultClass == true) {

		if (money < 30000) {

			money += moneyWorth;
		}

		if (moneyWorth == 4.0) {

			if (money < 60000) {

				money += moneyWorth;

			}

		}


	}

	if (rookieClass == true) {

		if (money < 125000) {

			money += moneyWorth;

		}

	}

	if (wealthClass == true) {

		if (money < 250000) {

			money += moneyWorth;

		}

	}

	if (richClass == true) {

		if (money < 450000) {

			money += moneyWorth;

		}

	}

	if (proClass == true) {

		if (money < 650000) {

			money += moneyWorth;

		}

	}

	if (eliteClass == true) {

		if (money < 850000) {

			money += moneyWorth;

		}

	}

	if (legendClass == true) {

		if (money < 1600000) {

			money += moneyWorth;

		}

	}

	if (millionaireClass == true) {

		if (money < 2500000) {

			money += moneyWorth;

		}

	}

	return money;

}



int main() {

	sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();



	sf::RenderWindow window(sf::VideoMode(800, 600), "Money Simulator");



	sf::Clock clock;

	sf::Time time;


	// load the font
	sf::Font font;

	if (!font.loadFromFile("font.ttf")) {

		std::cout << "font didnt load" << std::endl;

	}



	sf::Text moneySign;

	moneySign.setFont(font);

	std::string yourMoney = toString<int>(money);

	moneySign.setString("Money: " + yourMoney);



	sf::Text upgradeHouseSign;

	upgradeHouseSign.setFont(font);

	upgradeHouseSign.setString("Upgrade House");

	upgradeHouseSign.setFillColor(sf::Color::Black);

	upgradeHouseSign.setCharacterSize(15);

	upgradeHouseSign.setPosition(635, 215);


	sf::Text buyNewHouseSign;

	buyNewHouseSign.setFont(font);

	buyNewHouseSign.setString("Buy New House");

	buyNewHouseSign.setFillColor(sf::Color::Black);

	buyNewHouseSign.setCharacterSize(15);

	buyNewHouseSign.setPosition(635, 290);


	sf::Texture SunTexture;

	SunTexture.loadFromFile("sun.png");



	sf::Sprite Sun(SunTexture);



	Sun.setPosition(640, -100);

	Sun.setScale(0.5, 0.5);



	sf::Texture TractorTexture;

	TractorTexture.loadFromFile("tractor.png");



	sf::Sprite Tractor(TractorTexture);



	Tractor.setPosition(420, 350);

	Tractor.setScale(0.75, 0.75);



	sf::Texture DirtTexture;

	DirtTexture.loadFromFile("dirt.jpg");



	sf::Sprite Dirt(DirtTexture);



	Dirt.setPosition(0, 500);

	Dirt.setScale(3, 1);



	sf::Texture GrassTexture;

	GrassTexture.loadFromFile("grass.png");



	sf::Sprite Grass(GrassTexture);



	Grass.setPosition(0, 425);

	Grass.setScale(0.5, 0.2);



	sf::Texture BarnTexture;

	BarnTexture.loadFromFile("BarnHouse.png");



	sf::Sprite Barn(BarnTexture);

	Barn.setPosition(-190, 125);

	Barn.setScale(0.5f, 0.5f);

	
	sf::Texture BarnTwoTexture;
	BarnTwoTexture.loadFromFile("BarnHouseStageTwo.png");

	sf::Sprite BarnTwo(BarnTwoTexture);
	BarnTwo.setPosition(-100, 145);
	BarnTwo.setScale(0.5f, 0.5f);

	// upgrade house button
	sf::RectangleShape uphButton;

	uphButton.setSize(sf::Vector2f(185, 50));

	uphButton.setFillColor(sf::Color::Yellow);

	uphButton.setPosition(630, 200);

	
	// buy house button
	sf::RectangleShape bnhButton;

	bnhButton.setSize(sf::Vector2f(185, 50));

	bnhButton.setFillColor(sf::Color::Yellow);

	bnhButton.setPosition(630, 275);

	//music.play();



	while (window.isOpen()) {

		sf::Event event;



		//events

		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {

				window.close();

			}

		}


		// mouse positions
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);

		sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

		// button pressed
		if (event.type == sf::Event::MouseButtonPressed && uphButton.getGlobalBounds().contains(mousePosF) && HMUU < 1 && money >= 25000) {

			moneyWorth += 1;

			money -= 25000;

			HMUU += 1;

		}

		// button pressed
		if (event.type == sf::Event::MouseButtonPressed && bnhButton.getGlobalBounds().contains(mousePosF) && HMUU == 1 && money >= 60000) {

			money -= 60000;

			defaultClass = false;
			rookieClass = true;

			stageOneHouse = false;
			stageTwoHouse = true;

			Tractor.setPosition(490, 350);

			moneyWorth += 0.5;
			HMUU += 1;

		}



		addMoney();

		yourMoney = toString<float>(money);

		moneySign.setString("Money: " + yourMoney);



		//updates

		window.setFramerateLimit(60);



		window.clear(sf::Color(51, 153, 255, 0));



		time = clock.getElapsedTime();

		//std::cout << 1.0f / time.asSeconds() << std::endl;
		std::cout << moneyWorth << std::endl;

		clock.restart().asSeconds();





		//draw objects



		window.draw(Sun);

		if (stageOneHouse == true) {
			window.draw(Barn);
		}
		if (stageTwoHouse == true) {
			window.draw(BarnTwo);
		}

		window.draw(Tractor);

		window.draw(Dirt);

		window.draw(Grass);

		window.draw(moneySign);

		window.draw(uphButton);

		window.draw(bnhButton);

		window.draw(upgradeHouseSign);

		window.draw(buyNewHouseSign);

		window.display();

	}



	return 0;

}
