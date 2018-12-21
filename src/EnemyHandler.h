#pragma once
#include "DisplayableObject.h"
#include <vector>
#include "Enemy.h"
#include "ProjectileHandler.h"
#include "Player.h"
class EnemyHandler :
	public DisplayableObject
{
public:
	EnemyHandler(BaseEngine* pEngine, ProjectileHandler* ph, Player* p);
	~EnemyHandler();
private:
	std::vector<Enemy*> enemies;
	ProjectileHandler* projectileHandler;
	Player* player;
public:
	void addEnemy(Enemy* newEnemy);
	void Draw();
	void DoUpdate(int iCurrentTime);
	void detectCollision();
	bool isWon();
};

