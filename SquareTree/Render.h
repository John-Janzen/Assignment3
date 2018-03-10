#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include "Receiver.h"
#include "Messenger.h"
#include "GameObject.h"

class Render : Receiver
{
public:
	Render();
	~Render();

	bool Init();
	bool Load();
	bool Update();

	SDL_Texture* loadTexture(std::string);

private:
	//SDL_Surface * _screenSurface = NULL;
	
	SDL_Window * _window = NULL;
	SDL_Renderer * _renderer = NULL;
	SDL_Texture * _texture = NULL;

	GameObject *_game_surface;

	const int SCREEN_HEIGHT = 480;
	const int SCREEN_WIDTH = 640;
};

