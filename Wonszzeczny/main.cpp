#include <iostream>

#include "Engine.h"

int main()
{
	Engine* game = Engine::GetInstance();

	game->Init();

	sf::Clock clock;

	while (game->IsRunning())
	{
		sf::Time deltaTime = clock.restart();

		game->UpdateObjects(deltaTime.asSeconds());
		game->Render();
	}
}



