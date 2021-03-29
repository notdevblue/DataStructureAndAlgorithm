// 20219 한우엽

#include <iostream>

//int revint(int num);
//int digit(int num);

int rev(int num);

int main()
{
	int num;
	std::cout << "수 입력: ";
	std::cin >> num;

	rev(num);

	return(0);
}

//int revint(int num)
//{
//	int dig = digit(num);
//	int* numarr = new int[dig];
//	int rev = dig - 1;
//	int result = 0;
//
//	for (int i = 0; i < dig; ++i)
//	{
//		numarr[dig - i - 1] = num / pow(10, i + 1);
//	}
//	for (int i = 0; i < dig; ++i)
//	{
//		result += numarr[i];
//	}
//
//
//	return result;
//}
//
//
//int digit(int num)
//{
//	int dig = 0;
//	while (num > 0)
//	{
//		num = num / 10;
//		++dig;
//	}
//	std::cout << dig << " 자리 수" << std::endl;
//	return dig;
//}

int rev(int num)
{
	
	if (num != 0)
	{
		std::cout << (num % 10);
		return rev(num / 10);
	}
	return(0);
}