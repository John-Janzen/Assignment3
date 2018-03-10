#pragma once
#include <queue>
#include <string>
#include <iostream>
#include <memory>

#include "Message.h"

class Receiver
{
public:
	Receiver() {}
	~Receiver() {}

	void handleMessage(std::shared_ptr<Message> msg) 
	{
		queue.push(msg);
	}
	
	std::queue<std::shared_ptr<Message>> queue;
private:
	
};
