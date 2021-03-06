#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include "MMusic.h"
#include "RTexture.h"
#include "World.h"
#include "Hero.h"
#include "Load.h"
#include "Game.h"

int main()
{		 
	sf::RenderWindow window(sf::VideoMode(800, 1000), "Fighter");

	Load::loading();
	World world(&window);
	Hero hero(&world);
	world.add(&hero);
	Game game(&world);
	window.setFramerateLimit(120);
	game.MainLoop();
	return 0;
}
