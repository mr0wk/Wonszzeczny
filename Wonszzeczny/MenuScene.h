#pragma once

#include "Scene.h"
#include "Engine.h"

class MenuScene : public Scene
{
public:
	void Init();
	void UpdateInput();
	void Update(float deltaTime);

private:
	void DisplayGameTitle(Engine* engine, sf::Vector2i& windowSize);
// TODO:
//private:
//	std::shared_ptr<Snake> _snake;
//
//	// The bounds in which the snake should animate
//	sf::FloatRect _menuSnakePatrolBounds;
};

