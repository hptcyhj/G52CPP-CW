#pragma once
#include "Projectile.h"
class EnemyProjectile :
	public Projectile
{
public:
	EnemyProjectile(BaseEngine* pEngine, int x, int y);
	~EnemyProjectile();
	void Draw();
	void DoUpdate(int iCurrentTime);
};

