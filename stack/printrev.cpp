#include "CStack.h"

int main()
{
	int size = 0;

	std::cout << "숫자 사이즈 입력: ";
	std::cin >> size;

	int* arr = (int*)malloc(sizeof(int) * size);


	std::cout << "\r\n숫자들 입력: " << std::endl;
	for (int i = 0; i < size; ++i)
	{
		std::cin >> arr[i];
	}

	CStack<int> stack(size);

	for (int i = 0; i < size; ++i)
	{
		stack.push(arr[i]);
	}

	for (int i = 0; i < size; ++i)
	{
		std::cout << stack.pop() << std::endl;
	}



	free(arr);

	return(0);
}