// 20219 �ѿ쿱

#include <iostream>

#pragma region Region



#pragma endregion


// ������ ���� ��ȯ ��
int _Check_return_ ctoi(char);
void checkDate(char[], int&, int&, int&);
void checkGender(char[], bool&);
const char* _Check_return_ checkRegion(char[]);

#pragma region �⺻ ����
int main()
{
			char	personal[14]	= {'\0',};
	const	char*	region;
	// ����, �λ�, ��õ, ����ֿ�, ���, ����, ���, �泲, ����, ����, ���
	int		year			= 0;
	int		month			= 0;
	int		date			= 0;
	bool	isMan;

	std::cout << "�ֹε�Ϲ�ȣ�� �Է��ϼ���." << std::endl;
	std::cin  >> personal;
	
	checkDate(personal, year, month, date);
	std::cout << year << "�� ";
	std::cout << month << "�� ";
	std::cout << date << "�� ��" << std::endl;

	checkGender(personal, isMan);
	if (isMan)
		std::cout << "����" << std::endl;
	else
		std::cout << "����" << std::endl;





	return(0);
}
#pragma endregion

int _Check_return_ ctoi(char ch)
{
	return ch - '0';
}

void checkDate(char personal[], int& year, int& month, int& date)
{
	year += ctoi(personal[0]) * 10;
	year += ctoi(personal[1]);
	if ((personal[6] == 1) || (personal[6] == 2))
	{
		year += 1900;
	}
	else
	{
		year += 2000;
	}

	month += ctoi(personal[2]) * 10;
	month += ctoi(personal[3]);

	date += ctoi(personal[4]) * 10;
	date += ctoi(personal[5]);
}

void checkGender(char personal[], bool& isMan)
{
	if ((personal[6] % 2) == 0)
	{
		isMan = false;
	}
	else
	{
		isMan = true;
	}
}

const char* _Check_return_ checkRegion(char personal[])
{
	int		birthRegion[]	= { 8,12,15,18,25,34,39,47,54,66,90 };
	int		regionNum		= 0;

	regionNum += ctoi(personal[7]) * 10;
	regionNum += ctoi(personal[8]);

	
	for (int i = 0; i < _countof(birthRegion); ++i)
	{
		regionNum <= birthRegion[i];
	}

	
	
}