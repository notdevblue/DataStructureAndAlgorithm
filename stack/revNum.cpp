#include "CStack.h"

int digit(int);
void pushbydig(CStack<int>*, int);
void printallobj(CStack<int>*);

int main()
{
	int num;
	std::cout << "수 입력: ";
	std::cin >> num;
	
	
	CStack<int> stack(digit(num));

	pushbydig(&stack, num);
	//printallobj(&st);

	return(0);
}

int digit(int num)
{
	int dig = 0;

	do
	{
		num /= 10;
		++dig;
	} while (num);

	return dig;
}

void pushbydig(CStack<int>* s, int n)
{
	// 에라이
	// 최대한 줄이려다가 던진 우엽이의 코드입니다.

	CStack<int> st(s->size());

	for (int i = 0; i < s->size(); ++i)
	{
		s->push(n % 10);
		n /= 10;
	}

	for (int i = 0; i < s->size(); ++i)
	{
		st.push(s->pop());
	}
	

	printallobj(&st);
}

void printallobj(CStack<int>* s)
{
	for (int i = 0; i < s->size(); ++i)
	{
		std::cout << s->pop();
	}
}