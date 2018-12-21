#include "header.h"
#include "templates.h"
#include "ProjectileHandler.h"
#include "PlayerProjectile.h"
#include "EnemyProjectile.h"
#include "Psyhy4CW4Engine.h"



ProjectileHandler::ProjectileHandler(BaseEngine* pEngine)
	: DisplayableObject(pEngine)
{
	m_iCurrentScreenX = m_iPreviousScreenX = 0;
	m_iCurrentScreenY = m_iPreviousScreenY = 0;

	m_iStartDrawPosX = 0;
	m_iStartDrawPosY = 0;

	m_iDrawWidth = GetEngine()->GetWindowWidth();
	m_iDrawHeight = GetEngine()->GetWindowHeight();

	SetVisible(true);
}


ProjectileHandler::~ProjectileHandler()
{
}


void ProjectileHandler::Draw()
{
	for (auto i = playerProjectiles.begin(); i != playerProjectiles.end(); i++)
		(*i)->Draw();
	for (auto i = enemyProjectiles.begin(); i != enemyProjectiles.end(); i++)
		(*i)->Draw();
}


void ProjectileHandler::DoUpdate(int iCurrentTime)
{
	if (((Psyhy4CW4Engine*)m_pEngine)->isPaused())
	{
		return;
	}
	for (auto i = playerProjectiles.begin(); i != playerProjectiles.end();)
	{
		if ((*i)->getDisappear())
		{

			(*i)->RedrawBackground();
			delete *i;
			i = playerProjectiles.erase(i);
		}
		else
		{
			(*i)->DoUpdate(iCurrentTime);
			i++;
		}
	}

	for (auto i = enemyProjectiles.begin(); i != enemyProjectiles.end();)
	{
		if ((*i)->getDisappear())
		{

			(*i)->RedrawBackground();
			delete *i;
			i = enemyProjectiles.erase(i);
		}
		else
		{
			(*i)->DoUpdate(iCurrentTime);
			i++;
		}
	}

	RedrawObjects();
}



void ProjectileHandler::playerFire(int x, int y)
{
	playerProjectiles.push_back(new PlayerProjectile(GetEngine(), x, y));
}


void ProjectileHandler::enemyFire(int x, int y)
{
	enemyProjectiles.push_back(new EnemyProjectile(GetEngine(), x, y));
}


bool ProjectileHandler::hitByPlayer(int x, int y, int width, int height)
{
	for (auto i = playerProjectiles.begin(); i != playerProjectiles.end(); i++)
	{
		if ((*i)->hit(x, y, width, height))
		{
			return true;
		}
	}
	return false;
}


bool ProjectileHandler::hitByEnemy(int x, int y, int width, int height)
{
	for (auto i = enemyProjectiles.begin(); i != enemyProjectiles.end(); i++)
	{
		if ((*i)->hit(x, y, width, height))
		{
			return true;
		}
	}
	return false;
}
