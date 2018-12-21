#pragma once
#include "Aircraft.h"
#include "MovementPosition.h"
class Enemy :
	public Aircraft
{
public:
	Enemy(BaseEngine* pEngine, const char* filename, int x, int y, ProjectileHandler* ph);
	~Enemy();
	void fire();
	void DoUpdate(int iCurrentTime);
private:
	int firedTime;
	MovementPosition obMovement;
public:
	void updatePosition(int iCurrentTime);
	void setNewDestination();
};

