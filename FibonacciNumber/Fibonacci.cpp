#include <iostream>

int fibonacci(int num);

int main()
{
	std::cout << "수 입력 (피보나치): ";
	int num;
	std::cin >> num;
	std::cout << fibonacci(num) << std::endl;

	return(0);
}

int fibonacci(int num)
{
	if (num == 1 || num == 2)
		return 1;
	else
	{
		return fibonacci(num - 1) + fibonacci(num - 2);
	}
	


	//static int fibo[50];
	//static int n = 1;
	//fibo[0] = 0;
	//fibo[1] = 1;
	//if (num == 0)
	//	return fibo[0];
	//else if (num == 1)
	//	return fibo[1];
	//++n;
	//fibo[n] = fibo[n - 1] + fibo[n - 2];
	//if (num == n)
	//	return fibo[num];
	//else
	//	fibonacci(num);
}