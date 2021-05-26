//20219 한우엽

#include <stack>
#include <conio.h>
#include <iostream>


int main()
{
	std::stack<char> numStack;
	std::string revStack;
	char buffer = '\0';
	int digits = 0;

	
	std::cout << "q 누를 시 종료\r\n";
	while (true)
	{
		buffer = _getch();
		std::cout << buffer;
		if (buffer == 'q')
			break;

		++digits;
		
		//   100,000,000
		//   887 6544321
		//   1,0 000,000
		if ((digits % 4) == 0)
		{
			numStack.push(',');
			++digits;
		}

		numStack.push(buffer);
	}


	while (!numStack.empty())
	{
		revStack += numStack.top();
		numStack.pop();
	}

	std::cout << "리버스 : ";
	for (char ch : revStack)
	{
		std::cout << ch;
		numStack.push(ch);
	}

	std::cout << std::endl;

	while (!numStack.empty())
	{
		std::cout << numStack.top();
		numStack.pop();
	}


	return(0);
}