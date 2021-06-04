#include <iostream>

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

	
	int nodeCount;
	std::cin >> nodeCount;
	
	int* data = (int*)malloc(sizeof(int) * nodeCount);

	for (int i = 0; i < nodeCount; ++i)
	{
		std::cin >> data[i];
	}
	
	for (int item = 0; item < nodeCount; ++item)
	{
		std::cout << data[item];
	}


	free(data);
	return(0);
}