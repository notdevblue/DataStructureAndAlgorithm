// 20219 �ѿ쿱
#include <iostream>


// Ʈ���� ������ Ȯ�� ( ��Ʈ = 1�� ������ )
int treeLevel(int input);
void subtreeBeginArr(int level, int input, int* numarr, int* arr);
void Foo(int* idxarr, int* numarr, int size);

int main()
{
#pragma region �ּ���


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

	//   "  (8 9 4)  (10 11 5 )  2"  "(12 13 6 ) (14 15 7 ) 3" 1

	// 1 2 4 8 16 32 64 128
	// ������ �Ʒ��� ���� ����
#pragma endregion

	int num15arr[15] = { 1, 2, 4, 8, 9, 5, 10, 11, 3, 6, 12, 13, 7, 14, 15 }; // <= ���� ��ȸ
	int num7arr[7] = { 1,2,3,4,5,6,7 };


	int input = 15;
	std::cout << "��� �� �Է�: " << std::endl;
	std::cin >> input;

	// ���� ��ȸ�� �־����ٰ� �ؼ� ���� ���ڰ� �ƴҶ��� ����ó���� ���� �ʾҾ��.
	int* numArr = (int*)malloc(sizeof(int) * input);
	std::cout << "���� ��ȸ �Է�" << std::endl;
	for (int i = 0; i < input; ++i)
	{
		std::cin >> numArr[i];
	}

	// ��ȭ����Ʈ���� �ϴ� �����մϴ�.
	subtreeBeginArr(treeLevel(input), input, numArr, nullptr);


	free(numArr);
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
	std::cout << "level : " << level << std::endl;;

	return level;
}

void subtreeBeginArr(int level, int count, int* numarr, int* arr)
{
	// level - 2 ��ŭ 1�� ���ϰ� level - 2 ��ŭ 3�� ���ϰ� level - 3 ��ŭ 1�� ���ϰ� level - 3 ��ŭ 3�� ����, while level - n != 0 <= subtree�� �����ϴ� ��ġ

	int* idxArr = (int*)malloc(sizeof(int) * count);
	for (int i = 0; i < count; ++i)
	{
		idxArr[i] = -1;
	}


	int idx = 0;
	int n = 2;

	

	while (level - n != 0)
	{
		for (int i = 0; i < level - n; ++i)
		{
			idxArr[idx] = numarr[idx];
			++idx;
		}
		for (int i = 0; i < level - n; ++i)
		{
			idxArr[idx] = numarr[idx];
			idx += 3;
		}

		++n;
	}
	idxArr[idx] = numarr[idx];

	Foo(idxArr, numarr, count);

	free(idxArr);
}

// ���Ҹ� �ϸ� ��
void Foo(int* idxArr, int* numarr, int size)
{
	int* numSave = (int*)malloc(sizeof(int) * size);

	for (int i = 0; i < size; ++i)
	{
		numSave[i] = numarr[i];
	}

	int numholder;

	for (int i = 0; i < size; ++i)
	{
		if (i == 0) continue;

		if (idxArr[i] == -1 && idxArr[i - 1] != -1)
		{
			numholder = numSave[i];
			numSave[i] = numSave[i - 1];
			numSave[i - 1] = numholder;
		}
	}



	std::cout << std::endl;
	
	// ������ ������ �ƴ� ��¸� �̷������ �Ǵ� �Ŷ� ��¸� �߽��ϴ�.
	for (int i = 1; i < size; ++i)
	{
		if ((i - 1== size / 2))
		{
			std::cout << numSave[0] << " ";
		}
		std::cout << numSave[i] << " ";
	}
#pragma region �ּ��� ������


	// 15
	// 1 "2 4 8 9  5  10 11" "3  6  12 13 7  14 15"
	// 1 "2 (4 8 9)  (5  10 11)" "3   (6  12 13) (7  14 15)"
	// 0  1  2 3 4    5  6  7     8    9  10 11   12 13 14 idx
	// 0, "1, 2, 5, 8, 9, 12" Ʈ���� �����ϴ� ��� idx
	
	// 1 2 4  8  9 5 10 11 3 6 12 13 7 14 15
	// 1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1


	// 7
	// 1 "2 3 4" "5 6 7"
	//   "3 4 2" "6 7 5" 1

	//   "3 2 4" 1 "6 5 7"
	
	// b  b       e  b       e
	// 1  2   3   4  5   6   7
	// 1, 2, -1, -1, 5, -1, -1

	// ���� ��ȸ �� �� 1 �������� ������ ����
	// ���� ��ȸ �ϸ� ���� ���� �ϳ��� �������� ��
	// ���� ��ȸ �Ҷ��� �߰��� �˴ϴ�
#pragma endregion

	free(numSave);
}