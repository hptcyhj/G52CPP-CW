#include "header.h"
#include "templates.h"
#include "Psyhy4Engine.h"
#include "Psyhy4UserControlObject.h"
#include "Psyhy4AutoMoveObject.h"



Psyhy4Engine::Psyhy4Engine()
	: ob1(NULL)
{
}


Psyhy4Engine::~Psyhy4Engine()
{
}


void Psyhy4Engine::SetupBackgroundBuffer()
{
	FillBackground(0xffffcc);

	DrawBackgroundPolygon(50, 100, 110, 100, 110, 120, 50, 120, 0xeeccff);
	DrawBackgroundPolygon(110, 100, 350, 100, 350, 120, 110, 120, 0x0000ff);
	DrawBackgroundTriangle(350, 100, 350, 120, 370, 110, 0x0000ff);
	DrawBackgroundPolygon(100, 60, 120, 40, 110, 60, 110, 160, 120, 180, 100, 160, 0xabcdef);

	DrawBackgroundString(400, 100, "Legend of Zelda", 0, NULL);

	obTileManager.SetSize(6, 6);

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			int red = rand() % 255;
			int green = rand() % 255;
			int blue = rand() % 255;
			int color = red * 65536 + green * 256 + blue;
			obTileManager.SetValue(i, j, color);
		}
	}
	obTileManager.SetBaseTilesPositionOnScreen(60, 200);
	obTileManager.DrawAllTiles(this, this->GetBackground(), 0, 0, 5, 5);
}


void Psyhy4Engine::DrawStringsUnderneath()
{
	char buf[128];
	sprintf(buf, "Ball's Height %d", ob2->getHeight());
	DrawForegroundString(400, 500, buf, 0x00ffff, NULL);
}


void Psyhy4Engine::UnDrawStrings()
{
	CopyBackgroundPixels(400, 500, 300, 30);
}


int Psyhy4Engine::InitialiseObjects()
{
	// Record the fact that we are about to change the array - so it doesn't get used elsewhere without reloading it
	DrawableObjectsChanged();

	// Destroy any existing objects
	DestroyOldObjects();

	ob1 = new Psyhy4UserControlObject(this);
	ob2 = new Psyhy4AutoMoveObject(this);


	// Creates an array to store the objects
	// Needs to have room for the NULL at the end
	CreateObjectArray(3);

	// You MUST set the array entry after the last one that you create to NULL, so that the system knows when to stop.
	// i.e. The LAST entry has to be NULL. The fact that it is NULL is used in order to work out where the end of the array is.
	StoreObjectInArray(0, ob1);
	StoreObjectInArray(1, ob2);
	StoreObjectInArray(2, NULL);
	return 0;
}


void Psyhy4Engine::MouseDown(int iButton, int iX, int iY)
{
	ob1->setPosition(iX, iY);
}
