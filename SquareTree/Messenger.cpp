#include "Messenger.h"

void Messenger::postMessage(std::shared_ptr<Message> msg)
{
	queue.push(msg);
	Update();
}

Messenger & Messenger::instance()
{
	static Messenger _m;
	return _m;
}

void Messenger::setReceiver(MSG_TYPE type, Receiver* r)
{
	_receivers.insert(std::pair<MSG_TYPE, std::vector<Receiver*>>(type, std::vector<Receiver*>()));

	std::vector<Receiver*>& receivers = _receivers[type];
	for (Receiver* each : receivers)
		if (each == r)
			return;
	receivers.push_back(r);
}

void Messenger::Update()
{
	DeliverMessage(queue.front());
	queue.pop();
}

void Messenger::DeliverMessage(std::shared_ptr<Message> msg)
{
	std::vector<Receiver*> & recievers = _receivers[msg->GetType()];
	for (Receiver* const each : recievers)
		each->handleMessage(msg);
}