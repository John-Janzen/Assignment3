#pragma once
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <vector>

#include "Message.h"
#include "Receiver.h"

// Singleton Message System
class Messenger
{
public:
	// Constructors

	bool Init() { return true; };

	// Destructors
	~Messenger() {}

	// Methods
	void postMessage(std::shared_ptr<Message> msg);
	static Messenger & instance();
	void setReceiver(MSG_TYPE type, Receiver* r);
	void Update();
	void DeliverMessage(std::shared_ptr<Message> msg);

private:
	Messenger() {};
	std::queue<std::shared_ptr<Message>> queue;
	std::map<MSG_TYPE, std::vector<Receiver*>> _receivers;
};
