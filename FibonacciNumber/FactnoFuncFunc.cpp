#include <iostream>

int fact(int num);

int main()
{
	int n;
	std::cout << "¼ö ÀÔ·Â: ";
	std::cin >> n;

	std::cout << fact(n) << std::endl;


	return(0);
}

int fact(int num)
{
	int result = 1;

	for (int i = 1; i <= num; ++i)
	{
		result *= i;
	}

	return result;
}