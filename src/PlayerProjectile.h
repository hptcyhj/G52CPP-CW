#pragma once
#include "Projectile.h"
class PlayerProjectile :
	public Projectile
{
public:
	PlayerProjectile(BaseEngine* pEngine, int x, int y);
	~PlayerProjectile();
	void Draw();
	void DoUpdate(int iCurrentTime);
};

