#pragma once
#include "DisplayableObject.h"
class Psyhy4UserControlObject :
	public DisplayableObject
{
public:
	Psyhy4UserControlObject(BaseEngine* pEngine);
	~Psyhy4UserControlObject();
	void Draw();
	void DoUpdate(int iCurrentTime);
public:
	void setPosition(int x, int y);
};

