#include <iostream>
#include <map>

int nodeCount(int n);

int main()
{
	// Key:   글 읽는 방식으로 숫자 매긴 순서
	// Value: 노드 값
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

	// 짝수 일 때는 n - 1을 근 노드로 사용
	// 홀수 일 때는 n 을 근 노드로 사용
	res -= n % 2 == 0 ? n - 1 : n;
	tree[1] = res;

	std::cout << "근 노드를 제외한 모든 노드의 합: " << res << std::endl;

	std::cout << "왼쪽 서브트리의 합: " << res / 2 << std::endl;
	std::cout << "오른쪽 서브트리의 합: " << (res % 2 == 0 ? res / 2 : res / 2 + 1) << std::endl;

	std::cout << "값 검증: " << (res / 2) + (res % 2 == 0 ? res / 2 : res / 2 + 1) << std::endl;

	// 4 일때
	// 58
	// 59
	

	return(0);
}


int nodeCount(int n)
{
	return pow(2, n) - 1;
}