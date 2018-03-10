#pragma once
#include <vector>

#include "GameObject.h"
class Scene
{
public:
	Scene();
	~Scene();

	void addObject(GameObject * obj) { _worldObjects.emplace_back(obj); }

private:
	std::vector<GameObject*> _worldObjects;
};

