#include "list.h"



int main()
{
	int menu;
	init();

	while (true)
	{
		std::cout << "1. 입력, 2. 출력, 3. 수정, 4. 삽입, 5. 삭제, 6. 종료";
		std::cout << "input menu: ";
		std::cin >> menu;

		switch (menu)
		{
		case 1:
			insert(tail);
			break;
		case 2:
			printlist(head);
			break;
		case 3:
			modify(head);
			break;
		case 4:
			insertData(head);
			break;
		case 5:
			del(head);
			break;
		case 6:
			break;

		default:
			break;
		}
		if (menu == 6) { break; }
	}

	
	return(0);
}