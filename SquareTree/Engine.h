#pragma once
#include <SDL.h>

#include "Render.h"
#include "Messenger.h"
#include "Input.h"
class Engine : Receiver
{
public:
	Engine();
	~Engine();

	bool Init();

	bool Update();

	bool GetState()
	{
		return quit;
	}
private:
	Render * renderer;
	Input * input;

	bool quit = false;
};

