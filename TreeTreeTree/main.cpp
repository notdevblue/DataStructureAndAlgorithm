#include <iostream>


// Ʈ���� ������ Ȯ�� ( ��Ʈ = 1�� ������ )
int treeLevel(int input);
void subtreeBeginArr(int level, int* arr);

int main()
{
	// 3
	// 1 2 3
	// 2 3 1
    
	// 2 1 3


	// 7
	// 1 "2 3 4" "5 6 7"
	//   "3 4 2" "6 7 5" 1

	//   "3 2 4" 1 "6 5 7"

	// ���� ��ȸ �� �� 1 �������� ������ ����
	// ���� ��ȸ �ϸ� ���� ���� �ϳ��� �������� ��
	// ���� ��ȸ �Ҷ��� �߰��� �˴ϴ�

	// 15
	// 1 "2 4 8 9  5  10 11" "3  6  12 13 7  14 15"
	// 1 "2 (4 8 9)  (5  10 11)" "3   (6  12 13) (7  14 15)"
	// 0  1  2 3 4    5  6  7     8    9  10 11   12 13 14 idx
	// 0, "1, 2, 5, 8, 9, 12" Ʈ���� �����ϴ� ��� idx

	// level - 1 ��ŭ 1�� ���ϰ� level - 1 ��ŭ 3�� ���ϰ� level - 2 ��ŭ 1�� ���ϰ� level - 2 ��ŭ 3�� ����, while level - n != 0

	//   "  (8 9 4)  (10 11 5 )  2"  "(12 13 6 ) (14 15 7 ) 3" 1

	// 1 2 4 8 16 32 64 128
	// ������ �Ʒ��� ���� ����


	int input;
	std::cin >> input;

	std::cout << treeLevel(input) << std::endl;


	//int nodeCount;
	//std::cin >> nodeCount;
	//
	//int* data = (int*)malloc(sizeof(int) * nodeCount);

	//for (int i = 0; i < nodeCount; ++i)
	//{
	//	std::cin >> data[i];
	//}
	//
	//for (int item = 0; item < nodeCount; ++item)
	//{
	//	std::cout << data[item];
	//}


	//free(data);
	return(0);
}


int treeLevel(int input)
{
	int level = 0;

	while (input > 0)
	{
		++level;
		input /= 2;
	}

	return level;
}

void subtreeBeginArr(int level, int* arr)
{
	// level - 1 ��ŭ 1�� ���ϰ� level - 1 ��ŭ 3�� ���ϰ� level - 2 ��ŭ 1�� ���ϰ� level - 2 ��ŭ 3�� ����, while level - n != 0 <= subtree�� �����ϴ� ��ġ

	int* temparr = new int[level];
	
	int idx = 0;
	int n = 0;



	while (level - n != 0)
	{
		for (int i = 0; i < level; ++i)
		{
			temparr[idx] = n;
			++idx;

		}
	}




	delete[] temparr;
}