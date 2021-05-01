// 20219 �ѿ쿱
#include <iostream>
#include <stack>
#include <Windows.h>
#define MAZESIZE_Y 7
#define MAZESIZE_X 7

#pragma region ���� ����

/// <summary>
/// 0 road, 1 wall, 2 start, 3 finish
/// </summary>
int g_maze[MAZESIZE_Y + 1][MAZESIZE_X + 1] =
{
	{1, 1, 1, 1, 1, 1, 1, 1 },
	{1, 2, 0, 0, 0, 1, 0, 1 },
	{1, 1, 1, 0, 1, 0, 0, 1 },
	{1, 1, 0, 0, 0, 0, 1, 1 },
	{1, 1, 1, 0, 1, 0, 0, 1 },
	{1, 1, 0, 0, 0, 1, 0, 1 },
	{1, 1, 1, 1, 1, 1, 3, 1 },
	{1, 1, 1, 1, 1, 1, 1, 1 }
};
typedef struct mh
{
	int x;
	int y;

}	movehistory;
	movehistory	g_history;

typedef struct mb
{
	int x;
	int y;
	int directionSelected;

	bool operator==(mh& ref)
	{
		return x == ref.x && y == ref.y;
	}

}	moveBackup;
	moveBackup g_backup;

std::stack<movehistory> g_stMove;
std::stack<moveBackup>	g_stBackup;
int						g_entryposX		= -1;
int						g_entryposY		= -1;
int						g_exitposX		= -1;
int						g_exitposY		= -1;

#pragma region �����濡�� ������ ���� �����
int						g_decideCount	= 0;
int						g_lastDirection	= -1;
bool					g_isReturned	= false;
enum direction
{
	Up		= 0,
	Down	= 1,
	Left	= 2,
	Right	= 3
};
#pragma endregion



#pragma endregion


#pragma region �Լ�

void init();
void render();
void findRoad();

#pragma endregion

int main()
{
	init();
	render();

	while (g_stMove.top().x != g_entryposX || g_stMove.top().y != g_entryposY)
	{
		findRoad();
		std::cout << "x: " << g_stMove.top().x << "\ty:" << g_stMove.top().y << std::endl;
		Sleep(100);
	}

	

	return(0);
}

void init()
{
	srand(unsigned(time(NULL)));

	for (int y = 0; y < MAZESIZE_Y; ++y)
	{
		for (int x = 1; x < MAZESIZE_X + 1; ++x)
		{
			if (g_maze[y][x] == 2) { g_entryposX = x; g_entryposY = y; }
			else if(g_maze[y][x] == 3) { g_exitposX = x; g_exitposY = y; }
		}
	}

	g_history.x = g_exitposX;
	g_history.y = g_exitposY;

	g_stMove.push(g_history);
}

void render()
{
	for (int y = 0; y < MAZESIZE_Y; ++y)
	{
		for (int x = 1; x < MAZESIZE_X + 1; ++x)
		{
			if (g_maze[y][x] == 1) { std::cout << "��"; }
			else { std::cout << "��"; }
		}
		std::cout << std::endl;
	}
}

// ���� ������ ���� �ּ�
/*
��� ���� ��
������ ������ ��ǥ ���� �� �ϰ��̳� ��
�� ���� ������ ������ ��ǥ�� ���ư�
*/

// ����� �� �ڵ��� ���輺
void findRoad()
{
	static	int		curX;
	static	int		curY;
			int		roadCount		= 0;
			bool	isUpRoad		= false;
			bool	isDownRoad		= false;
			bool	isLeftRoad		= false;
			bool	isRightRoad		= false;

	curX = g_stMove.top().x;
	curY = g_stMove.top().y;

	if (g_maze[curY - 1][curX] != 1 && g_lastDirection != direction::Down)
	{
		std::cout << "���� �� ���� ";
		isUpRoad = true;
		++roadCount;
	}
	if (g_maze[curY + 1][curX] != 1 && g_lastDirection != direction::Up)
	{
		std::cout << "�Ʒ��� �� ���� ";
		isDownRoad = true;
		++roadCount;
	}
	if (g_maze[curY][curX - 1] != 1 && g_lastDirection != direction::Right)
	{
		std::cout << "���� �� ���� ";
		isLeftRoad = true;
		++roadCount;
	}
	if (g_maze[curY][curX + 1] != 1 && g_lastDirection != direction::Left)
	{
		std::cout << "�����ʿ� �� ���� ";
		isRightRoad = true;
		++roadCount;
	}
	std::cout << std::endl;
	if (roadCount > 1) // ������
	{
		std::cout << "������" << std::endl;

		int	dir;

		g_backup.x = curX;
		g_backup.y = curY;

		if (g_isReturned)
		{
			
			bool	isSameDirection	= false;
			bool	isNotWall		= false;
			do
			{
				dir = rand() % 4;
				
				switch (dir)
				{
				case 0:
					g_backup.directionSelected = g_lastDirection = direction::Up;
					isNotWall = g_maze[curY - 1][curX] != 1;
					break;

				case 1:
					g_backup.directionSelected = g_lastDirection = direction::Down;
					isNotWall = g_maze[curY + 1][curX] != 1;
					break;

				case 2:
					g_backup.directionSelected = g_lastDirection = direction::Left;
					isNotWall = g_maze[curY][curX - 1] != 1;
					break;

				case 3:
					isNotWall = g_maze[curY][curX + 1] != 1;
					break;
				}
				
				isSameDirection = (dir != g_stBackup.top().directionSelected);


			}
			while (isSameDirection && isNotWall);
		}

		if (!g_isReturned)
			dir = rand() % 4;

		switch (dir)
		{
		case 0:
			g_backup.directionSelected = g_lastDirection = direction::Up;
			--curY;
			break;
		case 1:
			g_backup.directionSelected = g_lastDirection = direction::Down;
			++curY;
			break;
		case 2:
			g_backup.directionSelected = g_lastDirection = direction::Left;
			--curX;
			break;
		case 3:
			g_backup.directionSelected = g_lastDirection = direction::Right;
			++curX;
			break;
		}

		g_stBackup.push(g_backup);
		std::cout << "������ ���: " << g_stBackup.top().x << " " << g_stBackup.top().y << std::endl;

		g_isReturned = false;
	}
	else if (roadCount == 1) // ��������
	{
		std::cout << "��������" << std::endl;

		if (isUpRoad)
		{
			g_lastDirection = direction::Up;
			--curY;
		}
		else if (isDownRoad)
		{
			g_lastDirection = direction::Down;
			++curY;
		}
		else if (isLeftRoad)
		{
			g_lastDirection = direction::Left;
			--curX;
		}
		else
		{
			g_lastDirection = direction::Right;
			++curX;
		}
	}
	else // ���ٸ� ��
	{
		std::cout << "���ٸ� ��" << std::endl;

		g_isReturned = true;

		while (!(g_stBackup.top() == g_stMove.top()))
		{
			g_stMove.pop();
		}

		curX = g_stMove.top().x;
		curY = g_stMove.top().y;
	}

	g_history.x = curX;
	g_history.y = curY;

	g_stMove.push(g_history);
}