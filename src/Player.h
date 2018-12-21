#pragma once
#include "Aircraft.h"
#include "Psyhy4CW4TileManager.h"
#include "JPGImage.h"
class Player :
	public Aircraft
{
public:
	Player(BaseEngine* pEngine, const char* filename, const char* filename2, int x, int y, ProjectileHandler* ph, Psyhy4CW4TileManager* tm);
	~Player();
public:
	void DoUpdate(int iCurrentTime);
	void fire();
	void Draw();
private:
	int lives;
public:
	void getDamage();
	bool isOver();
	int getLives();
private:
	int score;
public:
	int getScore();
	void incScore();
private:
	Psyhy4CW4TileManager* obTileManager;
	bool isHurt;
	int hurtTime;
public:
	ImageData hurtImage;
};

