#pragma once
#include <memory>

enum MSG_TYPE {
	MESSAGE_VOID,
	RENDER_UPDATE,
	RENDER_LOAD,
	CHANGE_OBJECT,
	QUIT_GAME
};

class BaseContent 
{
public:
	virtual ~BaseContent() {};
};

class ChangeContent : public BaseContent
{
public:
	ChangeContent(std::string data) : _data(data) {}
	~ChangeContent() { _data.clear(); }
	std::string _data;
};

class Message {
public:
	// Constructors
	//Message() {};
	Message(MSG_TYPE type, BaseContent * content = nullptr) : _type(type), _content{ content } {};

	// Destructors
	~Message() 
	{ 
		delete(_content);
		_content = nullptr;
	};

	MSG_TYPE GetType() { return _type; }
	BaseContent * GetContent() { return _content; }
	void SetContent(BaseContent * content) { _content = content; }

private:
	MSG_TYPE _type;
	BaseContent * _content;
};