#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include <memory>

#include "Messenger.h"

class Input
{
public:
	Input();
	~Input();

	bool Init() { return true; };
	void Check();
	void Action(SDL_Event&);

private:
	SDL_Event e;
};

