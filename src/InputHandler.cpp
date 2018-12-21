#include "header.h"
#include "templates.h"
#include "InputHandler.h"



InputHandler::InputHandler(int x, int y)
	: coorX(x)
	, coorY(y)
	, offset(0)
{
	for (size_t i = 0; i < 100; i++)
	{
		input[i] = 0;
	}
}


InputHandler::~InputHandler()
{
}


void InputHandler::drawInput(BaseEngine* pEngine, int iKeyCode)
{
	if (iKeyCode == SDLK_BACKSPACE)
	{
		offset--;
		input[offset] = 0;
	}
	else
	{
		input[offset] = iKeyCode;
		offset++;
	}
	
	pEngine->DrawBackgroundRectangle(coorX, coorY, coorX + 600, coorY + 50, 0xffff00);
	pEngine->DrawBackgroundString(coorX, coorY, input, 0, pEngine->GetFont("Verdana.ttf", 25));
}
