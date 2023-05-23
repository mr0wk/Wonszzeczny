#include "MenuScene.h"
#include "Engine.h"

void MenuScene::Init()
{
	Engine* engine = Engine::GetInstance();
	sf::Vector2i windowSize = engine->GetWindowSize();
	float cellSize = engine->GetCellSize();

	PrintGameTitle(engine, windowSize);

}

void MenuScene::UpdateInput()
{
}

void MenuScene::Update(float deltaTime)
{
}

void MenuScene::PrintGameTitle(Engine* engine, sf::Vector2i& windowSize)
{
	std::shared_ptr<sf::Text> gameTitle = engine->CreateTextToPrint("SNAKE");
	gameTitle->setCharacterSize(60);
	gameTitle->setPosition(windowSize.x / 2 - gameTitle->getLocalBounds().width / 2.f, 60.f);
}
