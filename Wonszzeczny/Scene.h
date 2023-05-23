#pragma once

#include <SFML/Audio.hpp>

class Scene
{
public:
	virtual void Init() = 0;
	virtual void UpdateInput() = 0;
	virtual void Update(float deltaTime) = 0;

protected:
	sf::Music musicTrack;

	void SetMusicTrack(const std::string& musicTrack);
};

