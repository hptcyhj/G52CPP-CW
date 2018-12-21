#include "header.h"
#include "templates.h"
#include "Psyhy4CW4TileManager.h"
#include "JPGImage.h"



Psyhy4CW4TileManager::Psyhy4CW4TileManager(const char* filename)
	: TileManager(30, 30)
{
	image.LoadImage(filename);
}


Psyhy4CW4TileManager::~Psyhy4CW4TileManager()
{
}


void Psyhy4CW4TileManager::DrawTileAt(
	BaseEngine* pEngine,
	SDL_Surface* pSurface,
	int iMapX, int iMapY,
	int iStartPositionScreenX, int iStartPositionScreenY) const
{
	if (GetValue(iMapX, iMapY))
	{
		image.RenderImageWithMask(pSurface, 0, 0,
			iStartPositionScreenX,
			iStartPositionScreenY,
			30, 30);
	}
}