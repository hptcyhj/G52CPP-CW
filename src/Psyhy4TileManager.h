#pragma once
#include "TileManager.h"
class Psyhy4TileManager :
	public TileManager
{
public:
	Psyhy4TileManager();
	~Psyhy4TileManager();
	virtual void DrawTileAt(BaseEngine* pEngine, SDL_Surface* pSurface, int iMapX, int iMapY, int iStartPositionScreenX, int iStartPositionScreenY) const;
};

