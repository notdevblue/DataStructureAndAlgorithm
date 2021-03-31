	// 20219 ÇÑ¿ì¿±
	#include <iostream>

	int nMinus(int num);

	int main()
	{
		int input;
		std::cout << "¼ö ÀÔ·Â :";
		std::cin >> input;
		nMinus(input);

		return(0);
	}

	int nMinus(int num)
	{
		if (num == 0)
			return 0;

		std::cout << num-- << " ";
		return nMinus(num);

	}