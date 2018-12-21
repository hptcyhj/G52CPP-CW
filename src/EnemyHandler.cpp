#include "header.h"
#include "templates.h"
#include "EnemyHandler.h"
#include "Psyhy4CW4Engine.h"



EnemyHandler::EnemyHandler(BaseEngine* pEngine, ProjectileHandler* ph, Player* p)
	: DisplayableObject(pEngine),
	  projectileHandler(ph),
	  player(p)
{
	m_iCurrentScreenX = m_iPreviousScreenX = 0;
	m_iCurrentScreenY = m_iPreviousScreenY = 0;

	m_iStartDrawPosX = 0;
	m_iStartDrawPosY = 0;

	m_iDrawWidth = GetEngine()->GetWindowWidth();
	m_iDrawHeight = GetEngine()->GetWindowHeight();

	SetVisible(true);
}


EnemyHandler::~EnemyHandler()
{
}


void EnemyHandler::addEnemy(Enemy* newEnemy)
{
	enemies.push_back(newEnemy);
}


void EnemyHandler::Draw()
{
	for (auto i = enemies.begin(); i != enemies.end(); i++)
		(*i)->Draw();
}


void EnemyHandler::DoUpdate(int iCurrentTime)
{
	if (((Psyhy4CW4Engine*)m_pEngine)->isPaused())
	{
		return;
	}
	for (auto i = enemies.begin(); i != enemies.end(); i++)
		(*i)->DoUpdate(iCurrentTime);
}


void EnemyHandler::detectCollision()
{
	for (auto i = enemies.begin(); i != enemies.end();)
	{
		if (projectileHandler->hitByPlayer((*i)->getX(), (*i)->getY(), (*i)->getWidth(), (*i)->getHeight()))
		{
			(*i)->RedrawBackground();
			delete *i;
			i = enemies.erase(i);
			player->incScore();
		}
		else
		{
			i++;
		}
	}
}


bool EnemyHandler::isWon()
{
	return (enemies.size() == 0);
}
