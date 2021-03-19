// 20219 한우엽

#include <iostream>

#pragma region Region



#pragma endregion


// 오로지 숫자 변환 용
int _Check_return_ ctoi(char);
void checkDate(char[], int&, int&, int&);
void checkGender(char[], bool&);
const char* _Check_return_ checkRegion(char[]);

#pragma region 기본 문제
int main()
{
			char	personal[14]	= {'\0',};
	const	char*	region;
	// 서울, 부산, 인천, 경기주요, 경기, 강원, 충북, 충남, 전북, 전남, 경상
	int		year			= 0;
	int		month			= 0;
	int		date			= 0;
	bool	isMan;

	std::cout << "주민등록번호를 입력하세요." << std::endl;
	std::cin  >> personal;
	
	checkDate(personal, year, month, date);
	std::cout << year << "년 ";
	std::cout << month << "월 ";
	std::cout << date << "일 생" << std::endl;

	checkGender(personal, isMan);
	if (isMan)
		std::cout << "남자" << std::endl;
	else
		std::cout << "여자" << std::endl;





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