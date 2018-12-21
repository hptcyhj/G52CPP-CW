#include "header.h"
#include "templates.h"
#include "Psyhy4CW4Background.h"



Psyhy4CW4Background::Psyhy4CW4Background(BaseEngine* pEngine, const char* filename)
	: DisplayableObject(pEngine)
	, drawOffset(0)
{
	m_iCurrentScreenX = m_iPreviousScreenX = 0;
	m_iCurrentScreenY = m_iPreviousScreenY = 0;

	m_iStartDrawPosX = 0;
	m_iStartDrawPosY = 0;

	image.LoadImage(filename);

	m_iDrawWidth = GetEngine()->GetWindowWidth();
	m_iDrawHeight = GetEngine()->GetWindowHeight();

	SetVisible(true);
}


Psyhy4CW4Background::~Psyhy4CW4Background()
{
}


void Psyhy4CW4Background::Draw()
{
	image.RenderImage(GetEngine()->GetForeground(), 0, 0, 0, drawOffset, m_iDrawWidth, GetEngine()->GetWindowHeight() - drawOffset);
	image.RenderImage(GetEngine()->GetForeground(), 0, GetEngine()->GetWindowHeight() - drawOffset + 1, 0, 0, m_iDrawWidth, drawOffset);
	StoreLastScreenPositionForUndraw();
}


void Psyhy4CW4Background::DoUpdate(int iCurrentTime)
{
	if (drawOffset >= GetEngine()->GetWindowHeight())
	{
		drawOffset = 0;
	}

	drawOffset += 2;

	RedrawObjects();
}
