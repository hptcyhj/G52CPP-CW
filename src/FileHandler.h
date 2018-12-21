#pragma once
#include <cstdio>
#include "BaseEngine.h"
class FileHandler
{
public:
	FileHandler(const char* filename);
	~FileHandler();
private:
	std::FILE* file;
public:
	void printScores(BaseEngine* pEngine, int x, int y);
	void saveData(const char* username, int score);
};

