#include <iostream>

int noGaus(int);

int main()
{
	std::cout << noGaus(10) << std::endl;

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