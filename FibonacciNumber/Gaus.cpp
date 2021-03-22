#include <iostream>

int gaus(int n);

int main()
{
	int n;
	std::cout << "¼ö ÀÔ·Â: ";
	std::cin >> n;

	std::cout << gaus(n) << std::endl;
	
	return(0);
}

int gaus(int n)
{
	return ((1 + n) * n) / 2;
}
