#include <iostream>

int main()
{
	// 3
	// 1 2 3
	// 2 3 1
    
	// 2 1 3


	// 7
	// 1 "2 3 4" "5 6 7"
	//   "3 4 2" "6 7 5" 1

	//   "3 2 4" 1 "6 5 7"

	// ���� ��ȸ �� �� 1 �������� ������ ����
	// ���� ��ȸ �ϸ� ���� ���� �ϳ��� �������� ��
	// ���� ��ȸ �Ҷ��� �߰��� �˴ϴ�

	
	int nodeCount;
	std::cin >> nodeCount;
	
	int* data = (int*)malloc(sizeof(int) * nodeCount);

	for (int i = 0; i < nodeCount; ++i)
	{
		std::cin >> data[i];
	}
	
	for (int item = 0; item < nodeCount; ++item)
	{
		std::cout << data[item];
	}


	free(data);
	return(0);
}