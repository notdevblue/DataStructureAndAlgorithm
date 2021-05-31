// 20219 한우엽
#pragma once

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
BTreeNode* MakeBTreeNode(void);

// DeleteBTreeNode() 라는 함수를 만들어 bt가 가리키고 있는 메모리(BTreeNOde 자료형 크기)를 삭제한다.
void DeleteBTreeNode(BTreeNode*);

void SetData(BTreeNode*, BTData);
// SetData() 라는 함수를 만들고, 첫 번째 인자에는 정보를 넣을 노드의 주솟값을 넣고, 두 번째 인자에는 입력시킬 자룟값을 넣는다.

BTData GetData(BTreeNode*);

BTreeNode* GetLeftSubTree(BTreeNode*);
BTreeNode* GetRightSubTree(BTreeNode*);

void MakeLeftSubTree(BTreeNode*, BTreeNode*);
// MakeLeftSubTree()라는 함수를 만들고 첫 번쨰 인자로는 아버지 노드에 해당 하는 노드의 주솟값을 넣어 주고, 두 번째 인자로는 왼쪽 자식 노드로 연결할 노드의 주솟값을 넣어 준다.
void MakeRightSubTree(BTreeNode*, BTreeNode*);
// MakeRightSubTree()라는 함수를 만들고 첫 번쨰 인자로는 아버지 노드에 해당 하는 노드의 주솟값을 넣어 주고, 두 번째 인자로는 오른쪽 자식 노드로 연결할 노드의 주솟값을 넣어 준다.

void PostorderTraverse(BTreeNode* bt);
void PreorderTraverse(BTreeNode* bt);
void InorderTraverse(BTreeNode* bt);