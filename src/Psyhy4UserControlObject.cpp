#include "header.h"
#include "templates.h"
#include "Psyhy4UserControlObject.h"



Psyhy4UserControlObject::Psyhy4UserControlObject(BaseEngine* pEngine)
	: DisplayableObject(pEngine)
{
	m_iCurrentScreenX = m_iPreviousScreenX = 400;
	m_iCurrentScreenY = m_iPreviousScreenY = 200;

	m_iStartDrawPosX = 0;
	m_iStartDrawPosY = 0;

	m_iDrawWidth = 100;
	m_iDrawHeight = 100;

	SetVisible(true);
}


Psyhy4UserControlObject::~Psyhy4UserControlObject()
{
}


void Psyhy4UserControlObject::Draw()
{
	GetEngine()->DrawForegroundPolygon(
		m_iCurrentScreenX + 40, m_iCurrentScreenY + 10,
		m_iCurrentScreenX + 50, m_iCurrentScreenY,
		m_iCurrentScreenX + 60, m_iCurrentScreenY + 10,
		m_iCurrentScreenX + 60, m_iCurrentScreenY + 90,
		m_iCurrentScreenX + 80, m_iCurrentScreenY + 99,
		m_iCurrentScreenX + 20, m_iCurrentScreenY + 99,
		m_iCurrentScreenX + 40, m_iCurrentScreenY + 90,
		0xff0000);

	GetEngine()->DrawForegroundPolygon(
		m_iCurrentScreenX + 10, m_iCurrentScreenY + 45,
		m_iCurrentScreenX + 90, m_iCurrentScreenY + 45,
		m_iCurrentScreenX + 99, m_iCurrentScreenY + 55,
		m_iCurrentScreenX, m_iCurrentScreenY + 55,
		0xff0000);

	StoreLastScreenPositionForUndraw();
}


void Psyhy4UserControlObject::DoUpdate(int iCurrentTime)
{
	if (GetEngine()->IsKeyPressed(SDLK_UP))
		m_iCurrentScreenY -= 2;
	if (GetEngine()->IsKeyPressed(SDLK_DOWN))
		m_iCurrentScreenY += 2;
	if (GetEngine()->IsKeyPressed(SDLK_LEFT))
		m_iCurrentScreenX -= 2;
	if (GetEngine()->IsKeyPressed(SDLK_RIGHT))
		m_iCurrentScreenX += 2;

	if (m_iCurrentScreenX < 0)
		m_iCurrentScreenX = 0;
	if (m_iCurrentScreenX >= GetEngine()->GetWindowWidth() - m_iDrawWidth)
		m_iCurrentScreenX = GetEngine()->GetWindowWidth() - m_iDrawWidth;
	if (m_iCurrentScreenY < 0)
		m_iCurrentScreenY = 0;
	if (m_iCurrentScreenY >= GetEngine()->GetWindowHeight() - m_iDrawHeight)
		m_iCurrentScreenY = GetEngine()->GetWindowHeight() - m_iDrawHeight;

	RedrawObjects();
}


void Psyhy4UserControlObject::setPosition(int x, int y)
{
	m_iCurrentScreenX = x - 50;
	m_iCurrentScreenY = y - 50;
}
