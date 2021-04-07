// 20219 �ѿ쿱

#include <iostream>


#define SIZE 10

typedef struct
{
	char	stackArr[SIZE];
	int		topIndex;
	char	name;
}stack;

typedef stack* lpstack;

void init(lpstack lps, char c);
void push(lpstack lps, char ch);
char pop(lpstack lps);

int main()
{
	stack s1, s2;
	
	init(&s1, 'A');
	init(&s2, 'B');
	std::cout << std::endl;
	push(&s1, 'd');
	push(&s1, 'a');
	push(&s1, 't');
	push(&s1, 'a');
	
	
	push(&s2, 's');
	push(&s2, 't');
	push(&s2, 'a');
	push(&s2, 'c');
	push(&s2, 'k');

	for (int i = 0; i < 5; ++i)
	{
		std::cout << "pop s1: " << pop(&s1) << std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		std::cout << "pop s2:" << pop(&s2) << std::endl;
	}

	return(0);
}

void init(lpstack lps, char c)
{
	lps->topIndex = 0;
	lps->name = c;
	std::cout << "constructing stack" << lps->name << std::endl;
}

void push(lpstack lps, char ch)
{
	if (lps->topIndex == SIZE)
	{
		std::cout << "stack " << lps->name << " is full." << std::endl;
		return;
	}
	lps->stackArr[lps->topIndex] = ch;
	lps->topIndex++;
}

char pop(lpstack lps)
{
	if (lps->topIndex == 0)
	{
		std::cout << "stack  " << lps->name << " is empty" << std::endl;
		return(0);
	}
	lps->topIndex--;

	return lps->stackArr[lps->topIndex];
}