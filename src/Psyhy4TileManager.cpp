#include "header.h"
#include "templates.h"
#include "Psyhy4TileManager.h"



Psyhy4TileManager::Psyhy4TileManager()
	: TileManager(50, 50)
{
}


Psyhy4TileManager::~Psyhy4TileManager()
{
}


void Psyhy4TileManager::DrawTileAt(
	BaseEngine* pEngine, 
	SDL_Surface* pSurface, 
	int iMapX, int iMapY, 
	int iStartPositionScreenX, int iStartPositionScreenY) const
{
	pEngine->DrawRectangle(
		iStartPositionScreenX,
		iStartPositionScreenY,
		iStartPositionScreenX + GetTileWidth() - 1,
		iStartPositionScreenY + GetTileHeight() - 1,
		GetValue(iMapX, iMapY),
		pSurface);
}
