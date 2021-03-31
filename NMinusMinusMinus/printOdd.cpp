//20219 한우엽

#include <iostream>

void pOdd(int from, int to);

int main()
{
	int input1, input2;
	std::cout << "수 입력: ";
	std::cin >> input1 >> input2;

	pOdd(input1, input2);


	return(0);
}

void pOdd(int from, int to)
{
	if (from > to)
		return;

	if ((from % 2) == 0)
	{
		std::cout << from << " ";
	}
	pOdd(++from, to);
}