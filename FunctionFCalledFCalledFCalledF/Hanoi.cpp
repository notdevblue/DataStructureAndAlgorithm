// 20219 �ѿ쿱
#include <iostream>

void hanoi(int num, char from, char by, char to);

int main()
{
	int num;
	std::cout << "�� �Է�: ";
	std::cin >> num;

	hanoi(num, 'A', 'B', 'C');

	return(0);
}

void hanoi(int num, char from, char by, char to)
{
	if (num == 1)
		printf("���� 1�� %c ���� %c �� �̵�\r\n", from, to);
	else
	{
		hanoi(num - 1, from, to, by);
		printf("���� %d�� %c ���� %c �� �̵�\r\n", num, from, to);
		hanoi(num - 1, by, from, to);
	}
}