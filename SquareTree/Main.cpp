#include <iostream>
#include <string>
#include <SDL.h>
#include <stdio.h>
#include <thread>
#include <chrono>
#include <time.h>

#include "Engine.h"

Engine *engine;

void close()
{
	delete(engine);
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char* args[]) 
{
	//bool quit = false;
	engine = new Engine();

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		if (!engine->Init())
		{
			printf("Failed to initialize!\n");
			getchar();
		}
		else
		{
			while (!engine->GetState())
			{
				if (!engine->Update())
				{
					printf("Failed to Update!\n");
					getchar();
				}
				std::this_thread::sleep_for(std::chrono::microseconds(300));
			}
		}
	}

	close();
	//getchar();
	return 0;
}