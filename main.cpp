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



template <typename T>

std::string toString(T arg) {

	std::stringstream ss;

	ss << arg;

	return ss.str();

}



// HOW MUCH YOU UPGRADE (house)

int HMUU = 0;

bool firstSetting = true;
bool secondSetting = false;

float moneyWorth = 3.0;


bool stageOneHouse = true;
bool stageTwoHouse = false;

bool rookieCar = false;

bool defaultClass = true;

bool rookieClass = false;

bool wealthClass = false;

bool richClass = false;

bool proClass = false;

bool eliteClass = false;

bool legendClass = false;

bool millionaireClass = false;



long float money = 0.0;



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

	sf::Text settingSign;
	settingSign.setFont(font);
	settingSign.setString("Settings");
	settingSign.setFillColor(sf::Color::White);
	settingSign.setCharacterSize(25);
	settingSign.setPosition(3, 60);

	sf::Text BuyMV;

	BuyMV.setFont(font);

	BuyMV.setString("Buy New Car");

	BuyMV.setFillColor(sf::Color::Black);

	BuyMV.setCharacterSize(15);

	BuyMV.setPosition(635, 365);


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


	sf::Texture MiniTexture;


	MiniTexture.loadFromFile("MiniVan.png");


	sf::Sprite MiniVan(MiniTexture);

	MiniVan.setPosition(490, 350);

	MiniVan.setScale(0.5, 0.5);


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


	sf::RectangleShape uphButton;

	uphButton.setSize(sf::Vector2f(185, 50));

	uphButton.setFillColor(sf::Color::Yellow);

	//uphButton.setPosition(630, 200);
	uphButton.setPosition(1000, 1000);


	sf::RectangleShape bnhButton;

	bnhButton.setSize(sf::Vector2f(185, 50));

	bnhButton.setFillColor(sf::Color::Yellow);

	//bnhButton.setPosition(630, 275);
	bnhButton.setPosition(1000, 1000);


	sf::RectangleShape bncButton;

	bncButton.setSize(sf::Vector2f(185, 50));

	bncButton.setFillColor(sf::Color::Yellow);

	//bncButton.setPosition(630, 350);
	bnhButton.setPosition(1000, 1000);


	sf::RectangleShape sttngButton;
	sttngButton.setSize(sf::Vector2f(160, 50));
	sttngButton.setFillColor(sf::Color::Black);
	sttngButton.setPosition(0, 50);

	sf::RectangleShape sttngButtonT;
	sttngButtonT.setSize(sf::Vector2f(160, 50));
	sttngButtonT.setFillColor(sf::Color::Black);
	sttngButtonT.setPosition(0, 50);
	
	// setting button background
	sf::RectangleShape sttngBtnBg;
	sttngBtnBg.setSize(sf::Vector2f(200, 200));
	sttngBtnBg.setFillColor(sf::Color::Black);
	sttngBtnBg.setPosition(155, 50);

	//music.play();



	while (window.isOpen()) {

		sf::Event event;



		//events

		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {

				window.close();

			}

		}



		sf::Vector2i mousePos = sf::Mouse::getPosition(window);

		sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

		if (event.type == sf::Event::MouseButtonPressed && uphButton.getGlobalBounds().contains(mousePosF) && HMUU < 1 && money >= 25000) {

			moneyWorth += 1;

			money -= 25000;

			HMUU += 1;

		}

		if (event.type == sf::Event::MouseButtonPressed && bnhButton.getGlobalBounds().contains(mousePosF) && HMUU == 1 && money >= 60000) {

			defaultClass = false;
			rookieClass = true;

			stageOneHouse = false;
			stageTwoHouse = true;

			Tractor.setPosition(490, 350);

			money -= 60000;
			moneyWorth += 0.5;
			HMUU += 1;

		}

		if (event.type == sf::Event::MouseButtonPressed && bncButton.getGlobalBounds().contains(mousePosF) && HMUU == 2 && money >= 25000) {


			rookieCar = true;
			moneyWorth += 0.5;
			money -= 25000;
			HMUU += 1;

		}

		if (event.type == sf::Event::MouseButtonPressed && sttngButton.getGlobalBounds().contains(mousePosF)) {

			firstSetting = false;
			secondSetting = true;

			sttngButtonT.setPosition(0, 95);
			settingSign.setPosition(3, 105);

		}

		if (event.type == sf::Event::MouseButtonPressed && sttngButtonT.getGlobalBounds().contains(mousePosF)) {

			firstSetting = true;
			secondSetting = false;

			sttngButtonT.setPosition(0, 50);
			settingSign.setPosition(3, 60);

		}

		addMoney();

		yourMoney = toString<float>(money);

		moneySign.setString("Money: " + yourMoney);



		//updates

		window.setFramerateLimit(60);



		window.clear(sf::Color(51, 153, 255, 0));



		time = clock.getElapsedTime();

		std::cout << 1.0f / time.asSeconds() << std::endl;
		//std::cout << moneyWorth << std::endl;
		//std::cout << firstSetting << "\n" << secondSetting << std::endl << std::endl;

		clock.restart().asSeconds();





		//draw objects



		window.draw(Sun);

		if (stageOneHouse == true) {
			window.draw(Barn);
		}
		if (stageTwoHouse == true) {
			window.draw(BarnTwo);
		}

		if (rookieCar == true) {
			window.draw(MiniVan);
		}

		if (rookieCar == false) {
			window.draw(Tractor);
		}
		window.draw(Dirt);

		window.draw(Grass);

		window.draw(moneySign);

		if (firstSetting == true) {
			window.draw(sttngButton);
			uphButton.setPosition(1000, 1000);
			bnhButton.setPosition(1000, 1000);
			bncButton.setPosition(1000, 1000);
			//sttngButtonT.setPosition(1000, 1000);
			//sttngButton.setPosition(0, 50);
		}
		if (secondSetting == true) {
			window.draw(sttngButtonT);
			window.draw(sttngBtnBg);

			//sttngButtonT.setPosition(0, 50);
			//sttngButton.setPosition(1000, 1000);
			uphButton.setPosition(162.65, 50);
			bnhButton.setPosition(162.65, 125);
			bncButton.setPosition(162.65, 200);

			upgradeHouseSign.setPosition(165, 70);
			buyNewHouseSign.setPosition(165, 145);
			BuyMV.setPosition(175, 215);

			window.draw(uphButton);
			window.draw(bnhButton);
			window.draw(bncButton);


			window.draw(upgradeHouseSign);
			window.draw(buyNewHouseSign);
			window.draw(BuyMV);
		}


		window.draw(settingSign);


		window.display();

	}



	return 0;

}
