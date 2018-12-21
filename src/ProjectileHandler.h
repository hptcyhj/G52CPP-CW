#pragma once
#include "DisplayableObject.h"
#include <vector>
#include "PlayerProjectile.h"
#include "EnemyProjectile.h"
class ProjectileHandler :
	public DisplayableObject
{
public:
	ProjectileHandler(BaseEngine* pEngine);
	~ProjectileHandler();
private:
	std::vector<PlayerProjectile*> playerProjectiles;
	std::vector<EnemyProjectile*> enemyProjectiles;
public:
	void Draw();
	void DoUpdate(int iCurrentTime);
	void playerFire(int x, int y);
	void enemyFire(int x, int y);
	bool hitByPlayer(int x, int y, int width, int height);
	bool hitByEnemy(int x, int y, int width, int height);
};

