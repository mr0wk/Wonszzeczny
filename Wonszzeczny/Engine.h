#pragma once

#include <SFML/Graphics.hpp>

#include "Scene.h"
#include "Updatable.h"

class Engine
{
public:
	~Engine();

	static Engine* GetInstance();
	void Init();
	const sf::Vector2i GetWindowSize() const;
	float GetCellSize() const;
	std::shared_ptr<sf::Text> CreateTextToPrint(const std::string& content);
	void AddDrawableToRender(std::shared_ptr<sf::Drawable> drawable);
	bool IsRunning() const;
	void UpdateObjects(float deltaTime);

private:
	static Engine* _instance;
	std::shared_ptr<sf::RenderWindow> _window;
	sf::Vector2i _windowSize = sf::Vector2i(600, 500);
	float _cellSize = 20.f;
	sf::Font _font;
	std::vector<std::shared_ptr<sf::Drawable>> _drawables;
	std::vector<std::shared_ptr<Updatable>> _updatables;
	std::shared_ptr<Scene> _scene = nullptr;

	Engine();

	template<class T> void LoadScene()
	{
		static_assert(std::is_base_of<Scene, T>::value, "T must inherit from Scene");

		_drawables.clear();
		_updatables.clear();
		//_collidables.clear();
		_scene = std::make_shared<T>();
		_scene->Init();
	}
};