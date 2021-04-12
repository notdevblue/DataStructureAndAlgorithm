// 20219 �ѿ쿱
#include "CStack.h"

int main()
{
	CStack<char> s1(10);

	s1.push('d');
	s1.push('u');
	s1.push('c');
	s1.push('k');
	
	std::cout << s1.size() << std::endl;

	std::cout << s1.pop() << std::endl;
	std::cout << s1.pop() << std::endl;
	std::cout << s1.pop() << std::endl;
	std::cout << s1.pop() << std::endl << std::endl;
	std::cout << s1.pop() << std::endl;


	return(0);
}

