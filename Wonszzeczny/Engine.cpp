#include <iostream>

#include "Engine.h"
#include "MenuScene.h"

Engine* Engine::_instance{ nullptr };

Engine::Engine()
{
	bool fontHasLoaded{ _font.loadFromFile("fonts\\default font.ttf") };

	if (!fontHasLoaded)
	{
		std::cerr << "Error: Failed to load the default font for the game. Font file not found or invalid." << std::endl;
	}
}

Engine::~Engine()
{

}

Engine* Engine::GetInstance()
{
	if (_instance == nullptr)
	{
		_instance = new Engine();
	}

	return _instance;
}

void Engine::Init()
{
	_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(_windowSize.x, _windowSize.y), "Wonszzeczny", sf::Style::Titlebar | sf::Style::Close);

	_window->setFramerateLimit(60);

	sf::Image icon;
	icon.loadFromFile("images\\icon.jpg");
	_window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	LoadScene<MenuScene>();
}

const sf::Vector2i Engine::GetWindowSize() const
{
	return _windowSize;
}

float Engine::GetCellSize() const
{
	return _cellSize;
}

std::shared_ptr<sf::Text> Engine::CreateTextToPrint(const std::string& content)
{
	std::shared_ptr<sf::Text> text = std::make_shared<sf::Text>();
	text->setFont(_font);
	text->setFillColor(sf::Color::White);
	text->setString(content);

	AddDrawableToRender(text);

	return text;
}

void Engine::AddDrawableToRender(std::shared_ptr<sf::Drawable> drawable)
{
	_drawables.push_back(drawable);
}

bool Engine::IsRunning() const
{
	return _window->isOpen();
}

void Engine::UpdateObjects(float deltaTime)
{
	sf::Event event;

	while (_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			_window->close();
			
			return;
		}

		for (size_t i = 0; i < _updatables.size(); i++)
		{
			_updatables[i]->Update(deltaTime);
		}

		if (_scene)
		{
			_scene->Update(deltaTime);
		}
	}
}

void Engine::Render()
{
	_window->clear();

	for (size_t i = 0; i < _drawables.size(); i++)
	{
		_window->draw(*_drawables[i]);
	}

	_window->display();
}


