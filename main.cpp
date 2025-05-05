#include "Bat.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

int main()
{
	// Create a Video mode object
	VideoMode vm(1920, 1080);

	// Create and Open a window for game
	RenderWindow window(vm, "Pong Game!!", Style::Fullscreen);
	int score = 0;
	int lives = 3;

	// Create a bat at the bottom center of the screen;
	Bat bat(1920 / 2, 1080 - 20);
	//
	// Create a text object called HUD
	Text hud;
	Font font;
	font.loadFromFile("fonts/Gameplay.ttf");
	// Set the font to our retro-style
	hud.setFont(font);
	// make it nice and big size
	hud.setCharacterSize(75);
	//Chose color for font
	hud.setFillColor(Color::White);
	hud.setPosition(20, 20);


	// Here is our clock for timing everything
	Clock clock;

	while (window.isOpen())
	{
		//****************************
		//Handle the player input
		//****************************
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				// Quit the game when the window is closed
				window.close();
		}
		// Handle the Player quiting
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		// Handle the pressing and relising the arrow kkey for left and right
		// Left arrow key
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			bat.moveLeft();
		}
		else
		{
			bat.stopLeft();
		}
		// Right arrow key
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			bat.moveRight();
		}
		else
		{
			bat.stopRight();
		}



		//*****************************
		//Update the bat, the ball and the HUD
		//*****************************
		// Update the delta time
		Time dt = clock.restart();
		bat.update(dt);

		// Update the HUD text
		std::stringstream ss;
		ss << "Score: " << score << " Lives: " << lives;
		hud.setString(ss.str());



		//*****************************
		//Draw the bat, the ball and the HUD
		//*****************************
		window.clear();
		window.draw(hud);
		window.draw(bat.getShape());
		window.display();

	}

	return 0;
}