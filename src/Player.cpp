#include "header.h"
#include "templates.h"
#include "Player.h"
#include "JPGImage.h"
#include "PlayerProjectile.h"
#include "Psyhy4CW4TileManager.h"



Player::Player(BaseEngine* pEngine, const char* filename, const char* hurtimage, int x, int y, ProjectileHandler* ph, Psyhy4CW4TileManager* tm)
	: Aircraft(pEngine, filename, x, y, ph)
	, lives(3)
	, score(0)
	, obTileManager(tm)
	, isHurt(false)
	, hurtTime(-1)
{
	ImageData temp;
	temp.LoadImage(hurtimage);
	hurtImage.ShrinkFrom(&temp, 2);
}


Player::~Player()
{
}

void Player::DoUpdate(int iCurrentTime)
{
	if (isHurt)
	{
		if (hurtTime == -1)
		{
			hurtTime = iCurrentTime;
		}
		else if (iCurrentTime - hurtTime > 1500)
		{
			isHurt = false;
			hurtTime = -1;
		}
	}

	if (GetEngine()->IsKeyPressed(SDLK_UP))
		m_iCurrentScreenY -= 4;
	if (GetEngine()->IsKeyPressed(SDLK_DOWN))
		m_iCurrentScreenY += 4;
	if (GetEngine()->IsKeyPressed(SDLK_LEFT))
		m_iCurrentScreenX -= 4;
	if (GetEngine()->IsKeyPressed(SDLK_RIGHT))
		m_iCurrentScreenX += 4;

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

void Player::fire()
{
	projectileHandler->playerFire(m_iCurrentScreenX + image.GetWidth() / 2 - 7, m_iCurrentScreenY - 7);
}


void Player::getDamage()
{
	if (isHurt)
	{
		return;
	}
	isHurt = true;

	lives--;
	if (lives == 0)
	{
		lives = 0;
	}
	obTileManager->SetValue(lives, 0, 0);
	obTileManager->DrawAllTiles(m_pEngine, m_pEngine->GetForeground(), 0, 0, 2, 0);
}


bool Player::isOver()
{
	return lives == 0;
}


int Player::getLives()
{
	return lives;
}


int Player::getScore()
{
	return score;
}


void Player::incScore()
{
	score += 10;
}

void Player::Draw()
{
	if (isHurt)
	{
		hurtImage.RenderImageWithMask(GetEngine()->GetForeground(), 0, 0, m_iCurrentScreenX, m_iCurrentScreenY, image.GetWidth(), image.GetHeight());
	}
	else
	{
		image.RenderImageWithMask(GetEngine()->GetForeground(), 0, 0, m_iCurrentScreenX, m_iCurrentScreenY, image.GetWidth(), image.GetHeight());
	}
	StoreLastScreenPositionForUndraw();
}
