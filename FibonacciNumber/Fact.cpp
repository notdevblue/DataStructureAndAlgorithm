#include <iostream>

int fact(int num);


int main()
{
	int num;
	std::cout << "¼ö ÀÔ·Â: ";
	std::cin >> num;
	std::cout << fact(num) << std::endl;

	return(0);
}



int fact(int num)
{
	if (!num)
	{
		return 1;
	}
	else
	{
		return num * fact(num - 1);
	}

	//static int count = 1;
	//static int result = 1;
	//result *= count;
	//if (num == count)
	//	return result;
	//else
	//{
	//	++count;
	//	fact(num);
	//}
}