#include <iostream>


// 트리의 레벨을 확인 ( 루트 = 1로 생각함 )
int treeLevel(int input);
void subtreeBeginArr(int level, int input, int* numarr, int* arr);

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

	// 전위 순회 할 때 1 다음으로 나오는 것이
	// 후위 순회 하면 작은 나무 하나의 마지막이 됨
	// 중위 순회 할때는 중간이 됩니다

	// 15
	// 1 "2 4 8 9  5  10 11" "3  6  12 13 7  14 15"
	// 1 "2 (4 8 9)  (5  10 11)" "3   (6  12 13) (7  14 15)"
	// 0  1  2 3 4    5  6  7     8    9  10 11   12 13 14 idx
	// 0, "1, 2, 5, 8, 9, 12" 트리가 시작하는 노드 idx

	// level - 1 만큼 1을 더하고 level - 1 만큼 3을 더하고 level - 2 만큼 1을 더하고 level - 2 만큼 3을 더함, while level - n != 0

	//   "  (8 9 4)  (10 11 5 )  2"  "(12 13 6 ) (14 15 7 ) 3" 1

	// 1 2 4 8 16 32 64 128
	// 단위로 아레에 줄이 생김

	int num15arr[15] = { 1, 2, 4, 8, 9, 5, 10, 11, 3, 6, 12, 13, 7, 14, 15 }; // <= 전위 순회
	int num7arr[7] = { 1,2,3,4,5,6,7 };


	int input = 7;
	//std::cin >> input;

	// 포화이진트리만 일단 가능합니다.
	subtreeBeginArr(treeLevel(input), input, num7arr, nullptr);

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

void subtreeBeginArr(int level, int count, int* numarr, int* arr)
{
	// level - 1 만큼 1을 더하고 level - 1 만큼 3을 더하고 level - 2 만큼 1을 더하고 level - 2 만큼 3을 더함, while level - n != 0 <= subtree가 시작하는 위치

	int* temparr = (int*)malloc(sizeof(int) * count);
	for (int i = 0; i < count; ++i)
	{
		temparr[i] = -1;
	}


	int idx = 0;
	int n = 1;

	

	while (level - n != 0)
	{
		for (int i = 0; i < level - n; ++i)
		{
			temparr[idx] = numarr[idx];
			++idx;
		}
		for (int i = 0; i < level - n; ++i)
		{
			temparr[idx] = numarr[idx];
			idx += 3;
		}

		++n;
	}
	temparr[idx] = numarr[idx];

	for (int i = 0; i < count; ++i)
	{
		std::cout << temparr[i] << " ";
	}

	Foo(temparr, numarr, count);

	free(temparr);
}

void Foo(int* idxarr, int* numarr, int size)
{
	int* newArr = (int*)malloc(sizeof(int) * size);

	for (int i = 0; i < size; ++i)
	{
		
	}



	free(newArr);
}