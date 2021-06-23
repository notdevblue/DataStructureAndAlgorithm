#include <iostream>
#include <map>

int nodeCount(int n);

int main()
{
	// Key:   �� �д� ������� ���� �ű� ����
	// Value: ��� ��
	std::map<int, int> tree;


	int n;
	int nodes;
	
	std::cout << "N: ";
	std::cin >> n;

	nodes = nodeCount(n);
	std::cout << "Node: " << nodes << std::endl;

	int res = 0;
	
	
	
	for (int i = 1; i <= nodes; ++i)
	{
		res += i;
	}

	// ¦�� �� ���� n - 1�� �� ���� ���
	// Ȧ�� �� ���� n �� �� ���� ���
	res -= n % 2 == 0 ? n - 1 : n;
	tree[1] = res;

	std::cout << "�� ��带 ������ ��� ����� ��: " << res << std::endl;

	std::cout << "���� ����Ʈ���� ��: " << res / 2 << std::endl;
	std::cout << "������ ����Ʈ���� ��: " << (res % 2 == 0 ? res / 2 : res / 2 + 1) << std::endl;

	std::cout << "�� ����: " << (res / 2) + (res % 2 == 0 ? res / 2 : res / 2 + 1) << std::endl;

	// 4 �϶�
	// 58
	// 59
	

	return(0);
}


int nodeCount(int n)
{
	return pow(2, n) - 1;
}