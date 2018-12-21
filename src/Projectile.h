#pragma once
#include "DisplayableObject.h"
class Projectile :
	public DisplayableObject
{
public:
	Projectile(BaseEngine* pEngine, int x, int y);
	~Projectile();
protected:
	bool disappear;
public:
	void setDisappear();
	bool getDisappear();
	bool hit(int x, int y, int width, int height);
};

