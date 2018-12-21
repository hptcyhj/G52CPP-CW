#pragma once
#include "BaseEngine.h"
#include "Player.h"
#include <vector>
#include "Enemy.h"
#include "Psyhy4CW4TileManager.h"
#include "EnemyHandler.h"
#include "FileHandler.h"
#include "InputHandler.h"
#include "JPGImage.h"
  class Psyhy4CW4Engine :
	public BaseEngine
{
public:
	Psyhy4CW4Engine();
	~Psyhy4CW4Engine();
	void SetupBackgroundBuffer();
	int InitialiseObjects();
	void MouseDown(int iButton, int iX, int iY);
private:
	Player* player;
public:
	void GameAction();
private:
	ProjectileHandler* projectileHandler;
public:
	void DrawStringsOnTop();
private:
	Psyhy4CW4TileManager* obTileManager;
	EnemyHandler* enemyHandler;
	enum State { stateInit, stateMain, statePaused, stateRank, stateOver };
	State gameStatus;
public:
	void UndrawObjects();
	void DrawObjects();
	void KeyDown(int iKeyCode);
private:
	int pausedTime;
	FileHandler* scorefile;
	InputHandler* inputHandler;
	ImageData background;
public:
	bool isPaused();
};

