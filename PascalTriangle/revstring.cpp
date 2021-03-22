// 20219 �ѿ쿱

#include <iostream>

void inputStr(char[3][256]);
void printRev(char[3][256]);

int main()
{
	char str[3][256] = { "one", "two", "three" };
	inputStr(str);
	printRev(str);

	return(0);
}

void inputStr(char str[3][256])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 256; ++j)
		{
			str[i][j] = getchar();
			if (str[i][j] == '\n')
				break;
		}
	}
}

void printRev(char str[3][256])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 255; j >= 0; --j)
		{
			if(str[i][j] != '\0')
				std::cout << str[i][j];
		}
	}
}