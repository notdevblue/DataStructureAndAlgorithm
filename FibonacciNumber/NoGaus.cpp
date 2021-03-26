#include <iostream>

int noGaus(int);

int main()
{
	int num;
	std::cout << "¼ö ÀÔ·Â: ";
	std::cin >> num;

	std::cout << noGaus(num) << std::endl;

	return(0);
}

int noGaus(int num)
{
	if (!num)
		return 0;
	else
	{
		return num + noGaus(num - 1);
	}
	
}