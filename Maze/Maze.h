#pragma once
#include "Defines.h"
#include <sal.h>
#define SIZE_X 7
#define SIZE_Y 7


class Maze
{
private:


public:

	// 나중에 수정해야 함
	int m_maze[SIZE_Y][SIZE_X] =
	{
		{1, 1, 1, 1, 1, 1, 1 },
		{7, 0, 1, 0, 0, 0, 1 },
		{1, 0, 1, 0, 1, 0, 1 },
		{1, 0, 1, 0, 1, 1, 1 },
		{1, 0, 0, 0, 0, 0, 1 },
		{1, 0, 1, 0, 1, 0, 1 },
		{1, 1, 1, 1, 1, 8, 1 }
	};

	CONSTRUCTOR Maze();
	DESTRUCTOR ~Maze();

	
};

