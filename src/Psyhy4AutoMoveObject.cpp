#include "header.h"
#include "templates.h"
#include "Psyhy4AutoMoveObject.h"



Psyhy4AutoMoveObject::Psyhy4AutoMoveObject(BaseEngine* pEngine)
	: DisplayableObject(pEngine)
	, speedX(0)
	, speedY(0)
	, posX(0)
	, posY(0)
{
	posX = m_iCurrentScreenX = m_iPreviousScreenX = 650;
	posY = m_iCurrentScreenY = m_iPreviousScreenY = 100;

	m_iStartDrawPosX = 0;
	m_iStartDrawPosY = 0;

	m_iDrawWidth = 50;
	m_iDrawHeight = 50;

	SetVisible(true);
}


Psyhy4AutoMoveObject::~Psyhy4AutoMoveObject()
{
}


void Psyhy4AutoMoveObject::Draw()
{
	GetEngine()->DrawForegroundOval(m_iCurrentScreenX, m_iCurrentScreenY, 
		m_iCurrentScreenX + 49, m_iCurrentScreenY + 49, 0xccaaff);
	GetEngine()->DrawForegroundTriangle(m_iCurrentScreenX + 25, m_iCurrentScreenY,
		m_iCurrentScreenX + 3.35, m_iCurrentScreenY + 37.5,
		m_iCurrentScreenX + 46.65, m_iCurrentScreenY + 37.5, 0xffff00);
	GetEngine()->DrawForegroundTriangle(m_iCurrentScreenX + 25, m_iCurrentScreenY + 49,
		m_iCurrentScreenX + 3.35, m_iCurrentScreenY + 12.5,
		m_iCurrentScreenX + 46.65, m_iCurrentScreenY + 12.5, 0xffff00);

	StoreLastScreenPositionForUndraw();
}


void Psyhy4AutoMoveObject::DoUpdate(int iCurrentTime)
{
	if (m_iCurrentScreenY >= 500)
	{
		speedY = -28;
		m_iCurrentScreenY = 500;
	}
	else if (m_iCurrentScreenY <= 100)
	{
		speedY = 0;
		m_iCurrentScreenY = 100;
	}

	speedY += 1;

	posX += speedX;
	posY += speedY;

	m_iCurrentScreenX = posX;
	m_iCurrentScreenY = posY;
	RedrawObjects();
}


int Psyhy4AutoMoveObject::getHeight()
{
	return 500 - m_iCurrentScreenY;
}
