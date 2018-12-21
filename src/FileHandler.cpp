#include "header.h"
#include "templates.h"
#include "FileHandler.h"
#include <cstdio>
#include <cstring>



FileHandler::FileHandler(const char* filename)
	: file(NULL)
{
	file = fopen(filename, "r+");
}


FileHandler::~FileHandler()
{
}


void FileHandler::printScores(BaseEngine* pEngine, int x, int y)
{
	while (!feof(file))
	{
		y += 100;
		char name[30] = { 0 };
		char score[30] = { 0 };
		fscanf(file, "%s %s", name, score);
		pEngine->DrawBackgroundString(10, y, name, 0xffffff, pEngine->GetFont("Verdana.ttf", 30));
		pEngine->DrawBackgroundString(300, y, score, 0xffffff, pEngine->GetFont("Verdana.ttf", 30));
	}
	
	rewind(file);
}


void FileHandler::saveData(const char* username, int score)
{
	fseek(file, 0, SEEK_END);
	int error = fprintf(file, "%s %d\n", username, score);
	fclose(file);
}
