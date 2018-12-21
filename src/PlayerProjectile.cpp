#include "header.h"
#include "templates.h"
#include "PlayerProjectile.h"
#include "Psyhy4CW4Engine.h"



PlayerProjectile::PlayerProjectile(BaseEngine* pEngine, int x, int y)
	: Projectile(pEngine, x, y)
{
}


PlayerProjectile::~PlayerProjectile()
{
}


void PlayerProjectile::Draw()
{
	GetEngine()->DrawForegroundOval(m_iCurrentScreenX, m_iCurrentScreenY, m_iCurrentScreenX + 14, m_iCurrentScreenY + 14, 0x0000ff);
	StoreLastScreenPositionForUndraw();
}


void PlayerProjectile::DoUpdate(int iCurrentTime)
{
	m_iCurrentScreenY -= 4;

	if (m_iCurrentScreenY < 0)
	{
		m_iCurrentScreenY = 0;
		setDisappear();
	}

	RedrawObjects();
}
