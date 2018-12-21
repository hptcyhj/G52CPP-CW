#pragma once
#include "DisplayableObject.h"
class Psyhy4AutoMoveObject :
	public DisplayableObject
{
public:
	Psyhy4AutoMoveObject(BaseEngine* pEngine);
	~Psyhy4AutoMoveObject();
public:
	void Draw();
	void DoUpdate(int iCurrentTime);
protected:
	double speedX;
public:
	double speedY;
	double posX;
	double posY;
	int getHeight();
};

