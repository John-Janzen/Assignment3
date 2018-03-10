#include <string>
#include <iostream>

#include "Render.h"

Render::Render()
{
	Messenger::instance().setReceiver(MSG_TYPE::RENDER_UPDATE, this);
	Messenger::instance().setReceiver(MSG_TYPE::RENDER_LOAD, this);
	Messenger::instance().setReceiver(MSG_TYPE::CHANGE_OBJECT, this);
	printf("Render Init\n");
}

Render::~Render() 
{
	SDL_DestroyTexture(_texture);
	_texture = NULL;

	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	_window = NULL;
	_renderer = NULL;

	delete(_game_surface);
	printf("Render Delete\n");
}

bool Render::Init()
{
	bool success = true;

	_window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (_window == NULL)
	{
		printf("Window could not be create! SDL_ERROR: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
		if (_renderer == NULL)
		{
			printf("Renderer could not be create! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, 0xFF);

			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not be initialized! SDL_image Error %s\n", IMG_GetError());
				success = false;
			}
		}
	}

	if (!Load())
	{
		printf("Load Failed");
		success = false;
	}
	return success;
}

bool Render::Update()
{
	while (!this->queue.empty()) 
	{
		std::shared_ptr<Message> m = queue.front();
		switch (m->GetType())
		{
		case RENDER_LOAD:
			if (!Load())
				return false;
			break;
		case RENDER_UPDATE:

			SDL_RenderClear(_renderer);
			SDL_RenderCopy(_renderer, _texture, NULL, NULL);
			SDL_RenderPresent(_renderer);

			break;
		case CHANGE_OBJECT: {
			if (_game_surface == nullptr)
				_game_surface = new GameObject();
			ChangeContent* c = static_cast<ChangeContent*>(m->GetContent());
			
			break;
		}
			
		default:
			break;
		}
		queue.pop();
	}
	
	return true;
}

SDL_Texture * Render::loadTexture(std::string path)
{
	SDL_Texture * newTexture = NULL;

	SDL_Surface * loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s SDL_image Error %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unabe to create texture for %s! SDL_Error: %s\n", path.c_str(), SDL_GetError());
		}
		SDL_FreeSurface(loadedSurface);
	}
	return newTexture;
}

bool Render::Load()
{
	bool success = true;
	_texture = loadTexture("texture.png");
	if (_texture == NULL)
	{
		printf("Unable to load image %s! SDL_Error: %s\n", "hello_world.bmp", SDL_GetError());
		success = false;
	}
	return success;
}
