// 20219 �ѿ쿱
#pragma once
#include <iostream>

template<typename T>
class CStack
{
private:
	T* stackArr;
	int		topIndex;
	int		stacksize;

public:

	CStack(int size)
	{
		this->stacksize = size;
		stackArr = (T*)malloc(sizeof(T) * this->stacksize);
		topIndex = 0;
		std::cout << "constructing stack" << std::endl;
	}

	~CStack()
	{
		free(stackArr);
	}

	T pop()
	{
		if (topIndex == 0)
		{
			std::cout << "stack is empty" << std::endl;
			return(0);
		}
		topIndex--;

		return stackArr[topIndex];
	}

	void push(T ch)
	{
		if (topIndex == stacksize)
		{
			std::cout << "stack is full." << std::endl;
			return;
		}
		stackArr[topIndex] = ch;
		topIndex++;
	}

	int size()
	{
		return stacksize;
	}

};

