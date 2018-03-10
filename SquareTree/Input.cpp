#include "Input.h"

Input::Input() { printf("Input Init\n"); }

Input::~Input() { printf("Input Delete\n"); }

void Input::Check()
{
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
		{
			Messenger::instance().postMessage(std::make_shared<Message>(Message(QUIT_GAME)));
		}
		switch (e.type)
		{
		case SDL_KEYDOWN:
			//printf("Key Down\n");
			Action(e);
			break;
		default:
			break;
		}
		break;
	}
}

void Input::Action(SDL_Event & e)
{
	switch (e.key.keysym.sym)
	{
	case SDLK_UP:
		Messenger::instance().postMessage(std::make_shared<Message>(MSG_TYPE::CHANGE_OBJECT, new ChangeContent("up.bmp")));
		break;
	case SDLK_LEFT:
		Messenger::instance().postMessage(std::make_shared<Message>(MSG_TYPE::CHANGE_OBJECT, new ChangeContent("left.bmp")));
		break;
	case SDLK_RIGHT:
		Messenger::instance().postMessage(std::make_shared<Message>(MSG_TYPE::CHANGE_OBJECT, new ChangeContent("right.bmp")));
		break;
	default:
		break;
		
	}
}
