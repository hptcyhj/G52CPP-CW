#include "header.h"
#include "templates.h"
#include "Aircraft.h"
#include "JPGImage.h"
#include "ProjectileHandler.h"



Aircraft::Aircraft(BaseEngine* pEngine, const char* filename, int x, int y, ProjectileHandler* ph)
	: DisplayableObject(pEngine)
	, projectileHandler(ph)
{
	m_iCurrentScreenX = m_iPreviousScreenX = x;
	m_iCurrentScreenY = m_iPreviousScreenY = y;

	m_iStartDrawPosX = 0;
	m_iStartDrawPosY = 0;

	ImageData temp;
	temp.LoadImage(filename);
	image.ShrinkFrom(&temp, 2);

	m_iDrawWidth = image.GetWidth();
	m_iDrawHeight = image.GetHeight();

	SetVisible(true);
}


Aircraft::~Aircraft()
{
}


void Aircraft::Draw()
{
	image.RenderImageWithMask(GetEngine()->GetForeground(), 0, 0, m_iCurrentScreenX, m_iCurrentScreenY, image.GetWidth(), image.GetHeight());
	StoreLastScreenPositionForUndraw();
}

int Aircraft::getX()
{
	return m_iCurrentScreenX;
}


int Aircraft::getY()
{
	return m_iCurrentScreenY;
}

int Aircraft::getHeight()
{
	return m_iDrawHeight;
}


int Aircraft::getWidth()
{
	return m_iDrawWidth;
}
