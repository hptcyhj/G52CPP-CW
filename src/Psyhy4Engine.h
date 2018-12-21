#pragma once
#include "BaseEngine.h"
#include "Psyhy4TileManager.h"
#include "Psyhy4UserControlObject.h"
#include "Psyhy4AutoMoveObject.h"
class Psyhy4Engine :
	public BaseEngine
{
public:
	Psyhy4Engine();
	~Psyhy4Engine();
	void SetupBackgroundBuffer();
	void DrawStringsUnderneath();
	void UnDrawStrings();
protected:
	Psyhy4TileManager obTileManager;
public:
	int InitialiseObjects();
	void MouseDown(int iButton, int iX, int iY);
protected:
	Psyhy4UserControlObject* ob1;
	Psyhy4AutoMoveObject* ob2;
};

