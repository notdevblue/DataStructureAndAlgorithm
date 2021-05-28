// 20219 한우엽
#include <iostream>

typedef int BTData;
struct BTreeNode
{
	BTData data;
	// 트리 자료 구조에 실제 정보를 답고자 한느 자료형 선언
	struct BTreeNode* left;
	// 트리 구조의 왼쪽 자식 노드를 가리키기 위한 포인터 변수 선언
	struct BTreeNode* right;
	// 트리 구조의 오른쪽 자식 노드를 가리키기 위한 포인터 변수 선언
};
// MakeBTreeNode() 라는 함수를 만들어 BTreeNode형의 메모리를 만들 수 있도록 하고, 이 메모리의 주소값을 반환받을 수 있도록 한다.

BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* nd = new BTreeNode;
	// 동적 메모리를 할당하는 부분이다.
 

	nd->left = NULL;
	nd->right = NULL;
	// BTreeNode 형으로 생성된 nd의 left와 right 포인터에는 현재 대입되는 다른 노드의 주소가 없기 때문에  NULL 값을 넣는다. 이후에 자식 노드가 있는 경우에 그 주솟값을 여기에 넣게 된다.
	return nd;
	// nd 에 대한 정의가 모드 끝났으면 nd 의 주솟값을 반환해준다.
}

void DeleteBTreeNode(BTreeNode);
// DeleteBTreeNode() 라는 함수를 만들어 bt가 가리키고 있는 메모리(BTreeNOde 자료형 크기)를 삭제한다.

void DeleteBTreeNode(BTreeNode* bt)
{
	delete bt;
}


void SetData(BTreeNode, BTData);
// SetData() 라는 함수를 만들고, 첫 번째 인자에는 정보를 넣을 노드의 주솟값을 넣고, 두 번째 인자에는 입력시킬 자룟값을 넣는다.

void SetData(BTreeNode* bt, BTData data)
{
	bt->data = data;
}

BTData GetData(BTreeNode);
BTData GetData(BTreeNode* node)
{
	return node->data;
}

BTreeNode* GetLeftSubTree(BTreeNode*);
BTreeNode* GetLeftSubTree(BTreeNode* node)
{
	return node->left;
}

BTreeNode* GetRightSubTree(BTreeNode*);
BTreeNode* GetRightSubTree(BTreeNode* node)
{
	return node->right;
}

void MakeLeftSubTree(BTreeNode, BTreeNode);
// MakeLeftSubTree()라는 함수를 만들고 첫 번쨰 인자로는 아버지 노드에 해당 하는 노드의 주솟값을 넣어 주고, 두 번째 인자로는 왼쪽 자식 노드로 연결할 노드의 주솟값을 넣어 준다.
void MakeRightSubTree(BTreeNode, BTreeNode);
// MakeRightSubTree()라는 함수를 만들고 첫 번쨰 인자로는 아버지 노드에 해당 하는 노드의 주솟값을 넣어 주고, 두 번째 인자로는 오른쪽 자식 노드로 연결할 노드의 주솟값을 넣어 준다.

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->left != NULL)
		// 이미 자식 노드에 할당된 노드가 있다면, 기존 것을 삭제한다.
	{
		delete main->left;
	}

	main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->right != NULL)
	{
		delete main->right;
	}

	main->right= sub;
}


int main()
{
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode();
	
	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);

	std::cout << GetData(GetLeftSubTree(bt1)) << std::endl;
	std::cout << GetData(GetLeftSubTree(GetLeftSubTree(bt1))) << std::endl;

	DeleteBTreeNode(bt1);
	DeleteBTreeNode(bt2);
	DeleteBTreeNode(bt3);
	DeleteBTreeNode(bt4);
}