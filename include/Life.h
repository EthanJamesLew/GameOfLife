#pragma once
#include "World.h"
class Life : public World
{
public:
	Life(int x, int y) : World(x, y){}

	virtual void update();
};
