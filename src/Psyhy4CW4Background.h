#pragma once
#include "DisplayableObject.h"
#include "JPGImage.h"
class Psyhy4CW4Background :
	public DisplayableObject
{
public:
	Psyhy4CW4Background(BaseEngine* pEngine, const char* filename);
	~Psyhy4CW4Background();
private:
	ImageData image;
public:
	void Draw();
	void DoUpdate(int iCurrentTime);
private:
	int drawOffset;
};

