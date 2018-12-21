#pragma once
#include "DisplayableObject.h"
#include "JPGImage.h"
#include "ProjectileHandler.h"
class Aircraft :
	public DisplayableObject
{
public:
	Aircraft(BaseEngine* pEngine, const char* filename, int x, int y, ProjectileHandler* ph);
	~Aircraft();
protected:
	ImageData image;
public:
	void Draw();
public:
	int getX();
	int getY();
	int getHeight();
	int getWidth();
protected:
	ProjectileHandler* projectileHandler;
};

