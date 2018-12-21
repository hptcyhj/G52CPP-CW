#include "header.h"
#include "templates.h"
#include "EnemyProjectile.h"



EnemyProjectile::EnemyProjectile(BaseEngine* pEngine, int x, int y)
	: Projectile(pEngine, x, y)
{
}


EnemyProjectile::~EnemyProjectile()
{
}


void EnemyProjectile::Draw()
{
	GetEngine()->DrawForegroundOval(m_iCurrentScreenX, m_iCurrentScreenY, m_iCurrentScreenX + 14, m_iCurrentScreenY + 14, 0xff0000);
	StoreLastScreenPositionForUndraw();
}


void EnemyProjectile::DoUpdate(int iCurrentTime)
{
	m_iCurrentScreenY += 2;

	if (m_iCurrentScreenY >= GetEngine()->GetWindowHeight() - m_iDrawHeight)
	{
		m_iCurrentScreenY = GetEngine()->GetWindowHeight() - m_iDrawHeight;
		setDisappear();
	}

	RedrawObjects();
}
