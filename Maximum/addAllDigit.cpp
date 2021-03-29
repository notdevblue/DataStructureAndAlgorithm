// 20219 한우엽

#include <iostream>

int addAll(int num);

int main()
{
	int input;
	std::cout << "수 입력: ";
	std::cin >> input;

	std::cout << addAll(input) << std::endl;

	return(0);
}

int addAll(int num)
{
	static int result = 0;
	result += num % 10;
	if (num != 0)
		return addAll(num / 10);
	else
		return result;
}