#include "MenuScene.h"
#include "Engine.h"

void MenuScene::Init()
{
	Engine* engine = Engine::GetInstance();
	sf::Vector2i windowSize = engine->GetWindowSize();
	float cellSize = engine->GetCellSize();

	DisplayGameTitle(engine, windowSize);

}

void MenuScene::UpdateInput()
{
}

void MenuScene::Update(float deltaTime)
{
}

void MenuScene::DisplayGameTitle(Engine* engine, sf::Vector2i& windowSize)
{
	std::shared_ptr<sf::Text> gameTitle = engine->CreateTextToPrint("Wonszzeczny");
	gameTitle->setCharacterSize(45);
	gameTitle->setPosition(windowSize.x / 2 - gameTitle->getLocalBounds().width / 2.f, 60.f);
}
