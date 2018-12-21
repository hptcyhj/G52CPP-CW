#pragma once
#include "BaseEngine.h"
class InputHandler
{
public:
	InputHandler(int x, int y);
	~InputHandler();
private:
	int coorX;
	int coorY;
	int offset;
public:
	char input[100];
	void drawInput(BaseEngine* pEngine, int iKeyCode);
};

