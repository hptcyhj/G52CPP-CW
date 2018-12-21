#include "header.h"
#include "templates.h"
#include "Enemy.h"
#include "EnemyProjectile.h"
#include "Psyhy4CW4Engine.h"
#include <cstdlib>
#include <cmath>



Enemy::Enemy(BaseEngine* pEngine, const char* filename, int x, int y, ProjectileHandler* ph)
	: Aircraft(pEngine, filename, x, y, ph)
	, firedTime(0)
{
	setNewDestination();
}


Enemy::~Enemy()
{
}


void Enemy::fire()
{
	projectileHandler->enemyFire(m_iCurrentScreenX + image.GetWidth() / 2 - 7, m_iCurrentScreenY + image.GetHeight() - 7);
}


void Enemy::DoUpdate(int iCurrentTime)
{
	updatePosition(iCurrentTime);

	if (obMovement.HasMovementFinished(iCurrentTime))
	{
		setNewDestination();
		updatePosition(iCurrentTime);
	}
	
	if (iCurrentTime - firedTime > 1000)
	{
		fire();
		firedTime = iCurrentTime;
	}

	RedrawObjects();
}


void Enemy::updatePosition(int iCurrentTime)
{
	obMovement.Calculate(iCurrentTime);
	m_iCurrentScreenX = obMovement.GetX();
	m_iCurrentScreenY = obMovement.GetY();
}


void Enemy::setNewDestination()
{
	int destX = rand() % (m_pEngine->GetWindowWidth() - m_iDrawWidth);
	int destY = rand() % (m_pEngine->GetWindowHeight() / 2);
	int timespan = 10 * sqrt((m_iCurrentScreenX - destX) * (m_iCurrentScreenX - destX) + (m_iCurrentScreenY - destY) * (m_iCurrentScreenY - destY));
	obMovement.Setup(m_iCurrentScreenX, m_iCurrentScreenY, destX, destY, m_pEngine->GetTime(), m_pEngine->GetTime() + timespan);
}
