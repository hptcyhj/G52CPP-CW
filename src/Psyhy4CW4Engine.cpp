#include "header.h"
#include "templates.h"
#include "Psyhy4CW4Engine.h"
#include "JPGImage.h"
#include "Aircraft.h"
#include "Projectile.h"
#include "Player.h"
#include "Enemy.h"
#include "ProjectileHandler.h"
#include "Psyhy4CW4TileManager.h"
#include "Psyhy4CW4Background.h"
#include "EnemyHandler.h"



Psyhy4CW4Engine::Psyhy4CW4Engine()
	: player(NULL)
	, projectileHandler(NULL)
	, enemyHandler(NULL)
	, gameStatus(stateInit)
	, pausedTime(0)
	, scorefile(NULL)
	, inputHandler(NULL)
{
	obTileManager = new Psyhy4CW4TileManager("resources/images/health.png");
	scorefile = new FileHandler("score.txt");
	inputHandler = new InputHandler(100, 300);
	background.LoadImage("resources/images/background.png");

	obTileManager->SetSize(3, 1);

	for (int i = 0; i < 3; i++)
	{
		obTileManager->SetValue(i, 0, 1);
	}
}


Psyhy4CW4Engine::~Psyhy4CW4Engine()
{
}


void Psyhy4CW4Engine::SetupBackgroundBuffer()
{
	switch (gameStatus)
	{
	case stateInit:
		FillBackground(0xffffff);
		background.RenderImage(GetBackground(), 0, 0, 0, 0, GetWindowWidth(), GetWindowHeight());
		DrawBackgroundString(180, 300, "Space Battle", 0xffffff, GetFont("Verdana.ttf", 60));
		DrawBackgroundString(220, 450, "New Game (Press SPACE)", 0xffffff);
		DrawBackgroundString(220, 550, "Score Record (Press S)", 0xffffff);
		break;

	case stateRank:
		FillBackground(0xffffff);
		background.RenderImage(GetBackground(), 0, 0, 0, 0, GetWindowWidth(), GetWindowHeight());
		DrawBackgroundString(10, 10, "Name", 0xffffff, GetFont("Verdana.ttf", 30));
		DrawBackgroundString(300, 10, "Score (Press B to Go Back)", 0xffffff, GetFont("Verdana.ttf", 30));
		scorefile->printScores(this, 10, 10);
		break;

	case stateOver:
		FillBackground(0xffffff);
		background.RenderImage(GetBackground(), 0, 0, 0, 0, GetWindowWidth(), GetWindowHeight());
		DrawBackgroundRectangle(100, 300, 700, 350, 0xffff00);
		DrawBackgroundString(200, 50, "Game Over!", 0xffffff, GetFont("Verdana.ttf", 60));
		DrawBackgroundString(100, 200, "Enter your name (Press RETURN to finish)", 0xffffff, GetFont("Verdana.ttf", 20));
		break;
	}
}


int Psyhy4CW4Engine::InitialiseObjects()
{
	// Record the fact that we are about to change the array - so it doesn't get used elsewhere without reloading it
	DrawableObjectsChanged();

	// Destroy any existing objects
	DestroyOldObjects();

	projectileHandler = new ProjectileHandler(this);
	player = new Player(this, "resources/images/1.png", "resources/images/1B.png", 300, 700, projectileHandler, obTileManager);
	enemyHandler = new EnemyHandler(this, projectileHandler, player);
	enemyHandler->addEnemy(new Enemy(this, "resources/images/2B.png", 300, 30, projectileHandler));
	enemyHandler->addEnemy(new Enemy(this, "resources/images/4B.png", 400, 70, projectileHandler));
	enemyHandler->addEnemy(new Enemy(this, "resources/images/8B.png", 100, 200, projectileHandler));
	Psyhy4CW4Background* background = new Psyhy4CW4Background(this, "resources/images/background.png");

	CreateObjectArray(5);
	StoreObjectInArray(0, background);
	StoreObjectInArray(1, player);
	StoreObjectInArray(2, projectileHandler);
	StoreObjectInArray(3, enemyHandler);
	StoreObjectInArray(4, NULL);
	return 0;
}


void Psyhy4CW4Engine::MouseDown(int iButton, int iX, int iY)
{
	if (gameStatus != stateMain)
		return;

	player->fire();
}


void Psyhy4CW4Engine::GameAction()
{
	// If too early to act then do nothing
	if (!IsTimeToActWithSleep())
		return;

	// Don't act for another 15 ticks
	SetTimeToAct(5);

	switch (gameStatus)
	{
	case stateInit:
	case statePaused:
	case stateRank:
		break;

	case stateMain:
		UpdateAllObjects(GetModifiedTime());

		enemyHandler->detectCollision();

		if (enemyHandler->isWon())
		{
			gameStatus = stateOver;
			SetupBackgroundBuffer();
			Redraw(true);
		}

		else if (projectileHandler->hitByEnemy(player->getX(), player->getY(), player->getWidth(), player->getHeight()))
		{
			player->getDamage();
			if (player->isOver())
			{
				gameStatus = stateOver;
				SetupBackgroundBuffer();
				Redraw(true);
			}
		}
	}
}


void Psyhy4CW4Engine::DrawStringsOnTop()
{
	switch (gameStatus)
	{
	case Psyhy4CW4Engine::statePaused:
		DrawForegroundString(250, 370, "Paused!", 0xffffff, GetFont("Verdana.ttf", 50));
	case Psyhy4CW4Engine::stateMain:
		char buf[128];
		sprintf(buf, "Lives:", player->getLives());
		DrawForegroundString(10, 10, buf, 0xffffff, GetFont("Verdana.ttf", 25));

		sprintf(buf, "Score:%d", player->getScore());
		DrawForegroundString(10, 50, buf, 0xffffff, GetFont("Verdana.ttf", 25));

		obTileManager->SetBaseTilesPositionOnScreen(100, 10);
		obTileManager->DrawAllTiles(this, this->GetForeground(), 0, 0, 2, 0);
		break;

	default:
		break;
	}
}


void Psyhy4CW4Engine::UndrawObjects()
{
	if (gameStatus == stateMain || gameStatus == statePaused) // Not in initialise state
		BaseEngine::UndrawObjects();
}


void Psyhy4CW4Engine::DrawObjects()
{
	if (gameStatus == stateMain || gameStatus == statePaused) // Not in initialise state
		BaseEngine::DrawObjects();
}


void Psyhy4CW4Engine::KeyDown(int iKeyCode)
{
	switch (gameStatus)
	{
	case Psyhy4CW4Engine::stateInit:
		switch (iKeyCode)
		{
		case SDLK_ESCAPE:
			SetExitWithCode(0);
			break;
		case SDLK_SPACE:
			gameStatus = stateMain;
			SetupBackgroundBuffer();
			Redraw(true);
			break;
		case SDLK_s:
			gameStatus = stateRank;
			SetupBackgroundBuffer();
			Redraw(true);
			break;
		}
		break;
	case Psyhy4CW4Engine::stateMain:
		switch (iKeyCode)
		{
		case SDLK_SPACE:
			gameStatus = statePaused;
			pausedTime = GetModifiedTime();
			SetupBackgroundBuffer();
			Redraw(true);
			break;
		}
		break;
	case Psyhy4CW4Engine::statePaused:
		switch (iKeyCode)
		{
		case SDLK_SPACE:
			gameStatus = stateMain;
			IncreaseTimeOffset(pausedTime - GetModifiedTime());
			SetupBackgroundBuffer();
			Redraw(true);
			break;
		}
		break;
	case Psyhy4CW4Engine::stateRank:
		switch (iKeyCode)
		{
		case SDLK_b:
			gameStatus = stateInit;
			SetupBackgroundBuffer();
			Redraw(true);
			break;
		}
		break;
	case Psyhy4CW4Engine::stateOver:
		switch (iKeyCode)
		{
		case SDLK_RETURN:
			scorefile->saveData(inputHandler->input, player->getScore());
			SetExitWithCode(0);
			break;
		default:
			inputHandler->drawInput(this, iKeyCode);
			Redraw(true);
			break;
		}
		break;
	default:
		break;
	}
}


bool Psyhy4CW4Engine::isPaused()
{
	return gameStatus == statePaused;
}
