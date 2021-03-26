// 20219 한우엽
#include <iostream>

void hanoi(int num, char from, char by, char to);

int main()
{
	int num;
	std::cout << "수 입력: ";
	std::cin >> num;

	hanoi(num, 'A', 'B', 'C');

	return(0);
}

void hanoi(int num, char from, char by, char to)
{
	if (num == 1)
		printf("원반 1을 %c 에서 %c 로 이동\r\n", from, to);
	else
	{
		hanoi(num - 1, from, to, by);
		printf("원반 %d를 %c 에서 %c 로 이동\r\n", num, from, to);
		hanoi(num - 1, by, from, to);
	}
}