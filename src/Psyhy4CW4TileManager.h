#pragma once
#include "TileManager.h"
#include "JPGImage.h"
class Psyhy4CW4TileManager :
	public TileManager
{
public:
	Psyhy4CW4TileManager(const char* filename);
	~Psyhy4CW4TileManager();
	virtual void DrawTileAt(BaseEngine* pEngine, SDL_Surface* pSurface, int iMapX, int iMapY, int iStartPositionScreenX, int iStartPositionScreenY) const;
private:
	ImageData image;
};

