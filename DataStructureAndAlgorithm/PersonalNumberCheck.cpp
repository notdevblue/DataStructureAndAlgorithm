// 20219 �ѿ쿱

#include <iostream>

// ������ ���� ��ȯ ��
int _Check_return_	ctoi(char);

void				checkDate(char[], int&, int&, int&);
void				checkGender(char[], bool&);
int _Check_return_	checkRegion(char[]);
bool				checkValid(char[]);

int main()
{
	char	personal[14]		= {'\0',};
	char	regionName[][11]	= { "����", "�λ�", "��õ", "����ֿ�", "����ֿ��", "����", "���", "�泲", "����", "����", "���" };
	int		year				= 0;
	int		month				= 0;
	int		date				= 0;
	bool	isMan				= false;

	std::cout << "�ֹε�Ϲ�ȣ�� �Է��ϼ���." << std::endl;
	std::cin  >> personal;
	checkDate(personal, year, month, date);
	std::cout << year  << "�� ";
	std::cout << month << "�� ";
	std::cout << date  << "�� ��" << std::endl;

	checkGender(personal, isMan);
	if (isMan)
		std::cout << "����" << std::endl;
	else
		std::cout << "����" << std::endl;

	std::cout << regionName[checkRegion(personal)] << std::endl;
	
	if (checkValid(personal))
		std::cout << "��ȿ��" << std::endl;
	else
		std::cout << "��ȿ���� ����" << std::endl;

	return(0);
}

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

int _Check_return_ checkRegion(char personal[])
{
	int		birthRegion[]	= { 8,12,15,18,25,34,39,47,54,66,90 };
	int		regionNum		= 0;

	regionNum += ctoi(personal[7]) * 10;
	regionNum += ctoi(personal[8]);

	
	for (int i = 0; i < _countof(birthRegion); ++i)
	{
		if (regionNum <= birthRegion[i])
			return i;
	}

	return -1;
}

bool checkValid(char personal[])
{
	int personalNum[13];
	int check[13];
	int sum = 0;


	for (int i = 0; i < _countof(personalNum); ++i)
	{
		personalNum[i] = ctoi(personal[i]);
	}


	for (int i = 0; i < 8; ++i)
	{
		check[i] = personalNum[i] * (i + 2);
	}
	check[8]	= personalNum[8]	* 2;
	check[9]	= personalNum[9]	* 3;
	check[10]	= personalNum[10]	* 4;
	check[11]	= personalNum[11]	* 5;

	for (int i = 0; i < _countof(check) - 1; ++i)
	{
		sum += check[i];
	}

	return ((11 - (sum % 11)) % 10) == personalNum[12];
}