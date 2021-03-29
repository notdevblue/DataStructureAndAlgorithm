// 20219 �ѿ쿱

#include <iostream>

void gugu(int first, int second);

int main()
{
	gugu(2, 1);

	return(0);
}


void gugu(int first, int second)
{
	if (first == 10)
		return;

	std::cout << first << " x " << second << " = " << first * second << std::endl;
	
	if (second == 9)
		gugu(++first, second = 1);
	else
		gugu(first, ++second);
}