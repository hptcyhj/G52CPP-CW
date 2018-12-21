#include "header.h"
#include "templates.h"
#include "Projectile.h"



Projectile::Projectile(BaseEngine* pEngine, int x, int y)
	: DisplayableObject(pEngine)
	, disappear(false)
{
	m_iCurrentScreenX = m_iPreviousScreenX = x;
	m_iCurrentScreenY = m_iPreviousScreenY = y;

	m_iStartDrawPosX = m_iStartDrawPosY = 0;

	m_iDrawWidth = 15;
	m_iDrawHeight = 15;

	SetVisible(true);
}


Projectile::~Projectile()
{
}


void Projectile::setDisappear()
{
	disappear = true;
}


bool Projectile::getDisappear()
{
	return disappear;
}


bool Projectile::hit(int x, int y, int width, int height)
{
	int centerX = m_iCurrentScreenX + m_iDrawWidth / 2;
	int centerY = m_iCurrentScreenY + m_iDrawHeight / 2;
	int radius = m_iDrawHeight / 2;

	if (centerX > x - radius && centerX < x + width + radius &&
		centerY > y && centerY < y + height)
	{
		setDisappear();
		return true;
	}
	else if (centerX > x && centerX < x + width &&
			 centerY > y - radius && centerY < y + height + radius)
	{
		setDisappear();
		return true;
	}
	else if ((centerX - x) * (centerX - x) + (centerY - y) * (centerY - y) < radius * radius)
	{
		setDisappear();
		return true;
	}
	else if ((centerX - x) * (centerX - x) + (centerY - (y + height)) * (centerY - (y + height)) < radius * radius)
	{
		setDisappear();
		return true;
	}
	else if ((centerX - (x + width)) * (centerX - (x + width)) + (centerY - y) * (centerY - y) < radius * radius)
	{
		setDisappear();
		return true;
	}
	else if ((centerX - (x + width)) * (centerX - (x + width)) + (centerY - (y + height)) * (centerY - (y + height)) < radius * radius)
	{
		setDisappear();
		return true;
	}
	else
	{
		return false;
	}
}
