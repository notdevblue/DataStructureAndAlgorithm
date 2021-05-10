// 20219 한우엽
#include <iostream>
#include <stack>
#include <conio.h>

int dig = 1;
int num1 = 0;
int num2 = 0;


bool checkNumber(std::stack<char> st)
{
	return st.top() > '0' && st.top() < '9';
}

void addNumber1(std::stack<char> st)
{
	num1 += dig * st.top();
	dig *= 10;
}

void addNumber2(std::stack<char> st)
{
	num2 += dig * st.top();
	dig *= 10;
}

int main()
{
	std::stack<char> st;
	char input;
	


	while ((input = _getch()) != 13)
	{
		st.push(input);
	}

	// in  => 12 + 23
	// in  => 12 - 2 + 3
	// out => 32 + 21
	// out => 3 - 2 + 21

	while (!st.empty())
	{
		if (checkNumber(st))
		{
			addNumber1(st);
		}
		else
		{
			dig = 1;

			switch (st.top())
			{
			case '+':
				while (true)
				{
					// 하나 pop 해서 계속 숫자일때까지
					addNumber2(st);
				}
				break;

			case '-':

				break;

			case '*':

				break;

			case '/':

				break;

			default:
				std::cout << "알 수 없는 수식입니다. " << std::endl;
				return(-1);
			}


		}


		st.pop();
	}
	

	return(0);
}