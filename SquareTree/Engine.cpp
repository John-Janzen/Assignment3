#include "Engine.h"

Engine::Engine() 
{
	Messenger::instance().setReceiver(MSG_TYPE::QUIT_GAME, this);
	printf("Engine Init\n");
}

Engine::~Engine() 
{
	printf("Engine Delete\n");
	delete(renderer);
	delete(input);
}

bool Engine::Init()
{
	//bool success = true;
	renderer = new Render();
	if (!renderer->Init())
	{
		printf("Renderer Init Error");
		return false;
	}

	Messenger::instance().postMessage(std::make_shared<Message>(Message(RENDER_LOAD)));

	input = new Input();
	if (!input->Init())
	{
		printf("Messenger Init Error");
		return false;
	}
	return true;
}

bool Engine::Update()
{
	if (!this->queue.empty())
	{
		std::shared_ptr<Message> m = queue.front();
		switch (m->GetType())
		{
		case MSG_TYPE::QUIT_GAME:
			quit = true;
			break;
		default:
			break;
		}
		queue.pop();
	}
	input->Check();
	Messenger::instance().postMessage(std::make_shared<Message>(Message(RENDER_UPDATE)));
	return (!renderer->Update()) ? false : true;
}
