// 20219 한우엽

#include <iostream>

#define ARRSIZE 5

int findMax(int num[]);

int main()
{
	int input[ARRSIZE];
	std::cout << "수 입력: ";
	for (int i = 0; i < ARRSIZE; ++i)
	{
		std::cin >> input[i];
	}
	std::cout << findMax(input) << std::endl;

	return(0);
}

int findMax(int arr[])
{
	static int i = 0;
	static int temp = 0;

	if (temp <= arr[i])
	{
		temp = arr[i];
	}
	++i;
	if (i != ARRSIZE)
		return findMax(arr);
	else
		return temp;
}