// 20219 한우엽

#include <iostream>
#include <stack>


#define MAZESIZE_Y 7
#define MAZESIZE_X 7

// 그저 생각을 적은 주석
/*
모든 길을 돔
갈림길 나오면 좌표 저장 후 암곳이나 감
그 곳이 막히면 갈림길 좌표로 돌아감
*/

/// <summary>
/// 0 road, 1 wall, 2 start, 3 finish
/// </summary>
int g_maze[MAZESIZE_Y][MAZESIZE_X] =
{
	{1, 1, 1, 1, 1, 1, 1 },
	{2, 0, 0, 0, 1, 0, 1 },
	{1, 1, 0, 1, 0, 0, 1 },
	{1, 1, 0, 0, 0, 1, 1 },
	{1, 1, 0, 1, 0, 0, 1 },
	{1, 0, 0, 0, 1, 0, 1 },
	{1, 1, 1, 1, 1, 3, 1 }
};
typedef struct mh
{
	int x;
	int y;
}	movehistory;
	movehistory			g_history;
std::stack<movehistory> g_st;
int						g_entryposX	= -1;
int						g_entryposY	= -1;
int						g_exitposX	= -1;
int						g_exitposY	= -1;


void init();
void render();
void findRoad();

int main()
{
	render();

	return(0);
}

void init()
{
	for (int y = 0; y < MAZESIZE_Y; ++y)
	{
		for (int x = 0; x < MAZESIZE_X; ++x)
		{
			if (g_maze[y][x] == 2) { g_entryposX = x; g_entryposY = y; }
			else if(g_maze[y][x] == 3) { g_exitposX = x; g_exitposY = y; }
		}
	}
}


void render()
{
	for (int y = 0; y < MAZESIZE_Y; ++y)
	{
		for (int x = 0; x < MAZESIZE_X; ++x)
		{
			if (g_maze[y][x] == 1) { std::cout << "■"; }
			else { std::cout << "□"; }
		}
		std::cout << std::endl;
	}
}

void findRoad()
{
	



}