#include "CStack.h"
#include <conio.h>

int main()
{
	int size = 0;
	size = _getch() - '0';


	CStack<int> stack{size};

	for (int i = 0; i < size; ++i)
	{
		int data;
		std::cin >> data;
		stack.push(data);
	}

	for (int i = 0; i < size; ++i)
	{
		std::cout << stack.pop() << std::endl;
	}


	return(0);
}